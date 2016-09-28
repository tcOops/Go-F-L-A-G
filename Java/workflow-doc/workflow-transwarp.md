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
