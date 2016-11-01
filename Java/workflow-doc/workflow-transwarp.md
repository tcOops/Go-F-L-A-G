###对transwarp-workflow的跟进与理解
---

```
2016/09/26
　对workflow现阶段的理解：
首先从大的结构说起，最后workflow使用形式是： web UI　或者直接通过thrift|RPC提供API，当然web UI的形式也是转化为具体的一些API调用啦。
而提供给用户的接口，基本都是Task相关的，从代码中看就是:TaskManager这个class.分析一下taskManager里面的有两个方法提供了schedule这个函数，分别是
PostTaskChange和deployWorkflow的，也就是说分别是在新建工作流和新建Task之后会做一些schedule的操作。这个schedule函数是scheduleManage提供的一个方法。主要功能是提供delay的功能。
而delay很关键，里面有一句这样的代码：delayQueue.add(st);就是向delayQueue这个数据结构里面添加一个新的task。

下面基于这一点分析一下workflow的核心工作流程:
workflow最原始的任务是task，当新建了一个task之后需要首先持久化(persist)这个task相关的信息，包括id啊，pluginname啊等字段，还有定时信息等等。然后scheduleManage会将这个task包装成一个scheduleTask的中转状态放入delayQueue里面。这样随着用户不停的新建task,delayQueue里面的scheduleTask是会不停的增长的。
在workflow系统启动的时候，在大的start()函数里面也会包含scheduleManage的start()，分析一下相关代码：
        this.service = Executors.newSingleThreadExecutor();
        service.submit(new DelayTask());
这里的意思大概是：新建了一个线程专门用来关注delayTask这个class,当然delayTask实现了这个接口：
	DelayTask implements Runnable
他的run()里面最核心的代码：
	st = delayQueue.poll(DEFAULT_WAIT_INTERVAL_SECONDS, TimeUnit.SECONDS);
意思就是不停的从delayQueue里面取scheduleTask,没有的话可能需要被阻塞等待。

这里有一个要注意的地方：新建的话都是以workflow为单位，workflow也写成一个特殊的task进行persist和写入delayQueue,(用户新建只是持久化，只有在发布workflow的时候才会写入delayQueue）
而workflow里面的task只是进行persist，只有当workflow这个task被从delayQueue里面取出来的时候，才会从持久层里面把这个workflow里面(相关)的task取出来(也就是说deploy workflow的时候只是将workflow这个task加入到delay_queue，而不会将workflow里面的inner task加入进去，　直到执行scheduleManager里面的sbumit的时候，才考虑将一个workflow相关的task加入到delay_queue)，加入到delayQueue里面,而delayQueue是可以按照scheduleTime来自动进行排序的，所以很快就能执行该task。

把task从delayQueue取出来之后，要搞成一个execution,并且持久化这个execution, 所以其实只有task(workflow　| task)　以及execution是需要持久化的。
如果这时候发现某个task有依赖，那么给这个task的dependency的task'加一个监听器，之后等这个task'做完了之后，通过这个listener通知task依赖已经解决一个，然后check一下是否还有没有新的依赖？如果条件成熟，直接从持久层里面把execution取出来直接执行(不需要再进入delayQueue啦）

而execution是包含taskid的，在此基础上又添加了执行相关的一些额外信息，之后就要进行execute这个过程。
Execute是在excuteManager里面搞的，　有个execute函数，这个函数：
首先新建一个job -> JobFactory.newJob(execution)，　这个newJob(execution)里面比较复杂，会根据job中pluginname等字段返回不同类型的job。
JobManager.submit(job)
而jobManager的submit方法本质上是新建了一个jobTask-> pool.submit(new JobTask)，　而这个jobTask实现了runnable接口，
job.execute()这个函数里面有个call方法，而这个call方法所在的抽象类，被各种类型的job都实现了，比如FTPJob | ShellJob等等。

关于配置文件：
基本上workflow的配置分三种，task字段里面的配置，文件配置，父类的配置。
在JobFactory.newJob(execution)这个函数里面会混合上面三种配置，最终形成一个param.
之后在具体的job进行execute的时候才会去读取参数。

关于test:
不同的模块分开测试
　－　需要测试job的话，无依赖的情况直接自定义Job需要的参数配置，new Job, JobManager.submit(job)就ok啦。
　　　如果需要测试job之间的依赖解决，这显然还是要从scheduleManager那边测起，因为task之间的依赖是那一层解决的。
　－　需要测试schedule, Task的话都需要从上层开始搞起。


//RejudgeX　Test Shell - Dependency
    @Test(timeout = 10000)
    public void testEmsSqlandDepedency() throws Exception {
        runWith(new TestProcess() {
            @Override
            public void test() throws Exception {
                String ems_sql_exec = "beeline -u 'jdbc:hive2://127.0.0.1:10000/default' -n hadoop -f ";
                String ems_sql_dir = "\"/home/hadoop/hive-sql-test/\"";
                String ems_sql_name1 = "sql1";

                Task wf1 = ctx.taskMgr().createTask(Task.newWorkflow()).getResult();
                Task sh2 = ctx.taskMgr().createTask(Task.newShell(wf1.getId())).getResult();
                updateTaskConfig(ctx, sh2, emsSqlConfig(ems_sql_exec, ems_sql_dir, ems_sql_name1));

                String ems_sql_name2 = "sql2";
                Task sh3 = ctx.taskMgr().createTask(Task.newShell(wf1.getId())).getResult();
                sh3.setDependencies(new long[] {sh2.getId()});
                updateTaskConfig(ctx, sh3, emsSqlConfig(ems_sql_exec, ems_sql_dir, ems_sql_name2));
                ctx.taskMgr().updateTask(sh3);
            }
        });
    }


 //RejudgeX Test EMS-Sql
    @Test
    public void EMSSqlTestSubmit() throws Exception {
        Execution execution = new Execution.Builder()
                .id(3)
                .taskId(10)
                .scheduleTime(System.currentTimeMillis())
                .executeUser("system")
                .pluginName("emssql")
                .build();

        Job job = factory.newJob(execution);
        ActiveJob activeJob = jobMgr.submitJob(job);
        System.out.println(activeJob.awaitResult());
    }


//Config相关
job_max_running = 20

string_parameters {
  const {
    ems_sql_exec = "beeline -u 'jdbc:hive2://127.0.0.1:10000/default' -n hadoop -f "
    ems_sql_name = "sql1.sql"
  }
  var {
    ems_sql_dir = "\"/home/hadoop/hive-sql-test/\""
  }
}

shell_command = ""


-------------------------------------
关于workflow中几种模式的总结：
任务类型：
WORKFLOW
CALENDER
TRIGGER
DECISION
TEMPORARY
PLUGIN
重点是workflow/calender/trigger/plugin
calender:传统的定时任务，到了规定时间就跑，可能是每天的定时，也可能是每个月的定时
trigger是一个触发器
plugin就是一堆job的plugin



------------------------------------
scheduleManager文件解析:

