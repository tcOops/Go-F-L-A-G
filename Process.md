##在BigData方面的积累记录

---
TranSwarp相关：

```
Inceptor:

```
---

```
关于内存数据库与普通的磁盘数据库的对比分析：

  重点在于： 内存数据库处理一些实时性要求比较高的事务处理， 注意每段数据在内存中保存的时间是有限的， 所以过一段时间是需要将内存中数据写回到磁盘的。
```

```
关于OLAP与OLTP的简单理解：

  OLTP可以理解为传统意义上的数据库， 即联机处理一些在线的数据库事务（SQL语句， 对查询的实时性要求相对较高, 比较看重处理的吞吐量与延时
  OLAP是一种新式的概念，在数据地位提高的今天，需要对数据进行大量分析， 所以需要进行数据的持久化（保留各种历史版本，可以称之为数据仓库， 之后对这些数据进行分析，（ 实时性来说要求相对没那么高, 不准确， 追求的是分析的效率
```

```
WAL：

write-ahead-logging
  简单理解为就是先将日志写回磁盘，之后再进行普通的数据落盘。 相对来说， 可以在某种场景下减小数据回滚的量
```

```
Row-store | Column-store:

列式存储与行式存储

[简单分析](http://www.infoq.com/cn/articles/bigdata-store-choose)
  行存储的写入是一次性完成，消耗的时间比列存储少，并且能够保证数据的完整性，缺点是数据读取过程中会产生冗余数据，
如果只有少量数据，此影响可以忽略；数量大可能会影响到数据的处理效率。列存储在写入效率、保证数据完整性上都不如行存储，
它的优势是在读取过程，不会产生冗余数据，这对数据完整性要求不高的大数据处理领域很重要。

  如果首要考虑是数据的完整性和可靠性，那么行存储是不二选择，列存储只有在增加磁盘并改进软件设计后才能接近这样的目标。
如果以保存数据为主，行存储的写入性能比列存储高很多。在需要频繁读取单列集合数据的应用中，列存储是最合适的。
如果每次读取多列，两个方案可酌情选择：采用行存储时，设计中应考虑减少或避免冗余列；若采用列存储方案，
为保证读写入效率，每列数据尽可能分别保存到不同的磁盘上，多个线程并行读写各自的数据，
这样避免了磁盘竞用的同时也提高了处理效率。 无论选择哪种方案，将同内容数据聚凑在一起都是必须的，这是减少磁头在磁盘上的移动，提高数据读取时间的有效办法。
```

```
倒排索引:
```

```
MPP架构：
  Massively Parallel Processing, 一种非共享的结构， 节点之间他人通过网络进行互联， 并行数据库大都采用此种结构
```

```
分布式存储引擎：
  这是一个软件层的概念，主要可分为三个模块：RootServer, UpdateServer以及ChunkServer.
主要解决的问题是：试图将分布式系统进行统一管理以及调度， 包括解决分布式系统中常见的一些需要处理的问题：数据分布 | 负载均衡| 一致性问题 等等。 同时也可能会提供一些基本的有关存储的公用模块给其他应用使用。
  这样的话， 该引擎就相当于对其他层屏蔽了分布式系统在数据存储方面的差异，使之看起来像一个单机系统，这样其他应用就不需要再去考虑分布式系统数据存储的问题了。
  其他一些应用， 比如分布式数据库都是基于分布式存储引擎来进行开发。
```

```
区分Hive与HBase：
  Hive应该算是一个插件， 将标准的SQL进行解析
  Hbase是基于HDFS的一个数据库。
  两者的操作模式： Hive+HDFS / Hbase客户端
  两者皆为Hadoop生态下的重要组件， 其中HBase提供了一个客户端，用户可以基于这个客户端编写Map-Reduce程序，去操作Hbase
Hive是将标准SQL应用到HDFS上的一种技术，做了ETL以及SQL转换的工作
```

```
ZooKeeper的使用场景：
  [http://www.cnblogs.com/ggjucheng/p/3352614.html](http://www.cnblogs.com/ggjucheng/p/3352614.html)
```

```
有关JDBC的介绍：
 [https://www.javacodegeeks.com/2015/03/jdbc%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B.html](https://www.javacodegeeks.com/2015/03/jdbc%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B.html)
```

```
迭代计算的一些开源框架:
```

##azkaban文档：
[http://azkaban.github.io/azkaban/docs/latest/](http://azkaban.github.io/azkaban/docs/latest/)


```
Java Executors(线程池)
Java DelayQueue的使用
```

```
Java内部类使用
静态变量注意点：
```

```
关于git使用， 我特么终于知道这一点了: (remote端的URI用origin来表示， master是服务器端的branch， 所以git pull origin master)
假设a,b同时维护一个repo， 其中有a.cpp这个文件， 假设b改完a.cpp， 然后a什么都没改的话， a pull origin master，是没有任何问题的。
但是如果a进行了改动且和b最新的改动(也就是最新push的这一次或多次，在某些行存在差异的话， 因为pull=fetch+部分自动合并， 会有各种合并的提醒， >>>>>这种符号blabla)，
关键是， 如果a在上次pull origin master之后， b没有进行任何更新， 那么即使a有改动， a pull origin master 也不会有任何冲突， （即使真的有很多冲突）。

这一点很容易解释: git的原则是， 如果a之前已经pull了其他用户的改动， 那么a就对其他所有用户的编辑都很清楚，也就是很清楚自己的行为，那么做任何改动之后，重新pull之后不会做任何conflict提醒。
相反， 如果此时有其他用户有新的push，a不知道，那么a push的时候，就会发生conflict,而git不会在服务器端解决冲突， 只会要求用户在提交之前就确定自己想要提交的内容， 所以需要先pull下其他用户的改动，
然后在本地进行改动之后，再进行新的push。

注意： git服务器端似乎不会去check， 你未及时pull到local的其他用户的操作是不是对你本次的push有影响， 一律报错。 也就是说即使b用户添加了一个b.cpp文件，a用户没有及时pull， 那么a在改完a.cpp之后提交， 也依然会报错， 还是要先pull下b.cpp。(但是似乎此时不需要重新commit即可push啦， 而前一种情况， 在conflict自动merge之后还是需要commit一下才可以push， 否则git还默认你没有做改动。)

另外最好用git fetch + git merge, 新建一个分支tmp来fetch最新的服务器端代码, git pull origin master:tmp,
然后切换到需要比对的分支，比如git checkout gh-pages, 然后进行diff, git diff tmp,
有差异的话需要进行手动更新， 有需要的话可以再merge一下， 然后再push。

UPD:实在不行可以rebase啊，　再不行还可以git reset --hard啊！！
```

```
Java表达式计算引擎　JexlEngine
```

```
Java中final关键字的使用： 无论属性是基本类型还是引用类型，final所起的作用都是变量里面存放的“值”不能变。
值得注意的是：　引用类型变量里面放的是个地址，所以用final修饰引用类型变量指的是它里面的地址不能变，并不是说这个地址所指向的对象或数组的内容不可以变。
```

```
Cache写策略：
write through: 更新cache的同时同时更新memory,保持高一致性
write back:　只有cache中数据被替换时，才写回memory.
Write Miss:
  要么直接写回memory, 要么先将要写的块从memory调入cache,再更新cache.
```

```
对hive的认识
  Hive的特性应该是专门用来做数据仓库的，　特点当然就是支持类SQL啦，　在下层实际上还是转化为Map/Reduce任务来做。
  一般任务都是批处理来搞，实时性没那么好(Latency比较高)，不适合做实时在线的交互(实时交互还是用oracle或者hbase或者stream比较好)
Hive (CLI) Beeline:
```

```
Hive安装：
Hive是一个Hadoop的客户端，所以是依赖于hadoop存在的(不跑hadoop跑不了hive).Hive主要用来提供数据仓库的功能，　类似于数据库，依赖于hdfs，创建一些表，这些表实际上存在hdfs上。　但是表的结构很灵活，没有专门的存储格式，格式可以由用户来提供。
Hive的Metadata是需要保存的(因为需要upd之类)，所以一般存在RDBMS上。　默认hive1.0是存在derby(三种模式:in-memory | network | thrift),　但是我们可以通过修改conf存在mysql上，下一个mysql的jdbc驱动就好啦。hive提供各种jdbc的接口。
所以，当我们新建了一张表之后，可以去mysql里面check,因为里面会有相关的meta-data,但是hive创建的表本身还是存在hdfs上哒。
```

```
关于hive的三种连接方式:
CLI
Web UI
jdbc
对于CLI，有hive自己的一套标准（类似mysql提供的CLI, 不同应用提供的CLI不一样，　一般这个也不统一，取决于CLI的实现　hive与mysql有区别
对于jdbc，那就完全一样啦，Class.forname...DriverManager,所以只要是提供jdbc接口的应用，那么一定要在驱动程屏蔽这种差异
比如TranSwarp的Inceptor上层在开发的jdbc与odbc驱动，就是为了给用户提供在java环境与windows环境下进行简单调用Inceptor的方便。
```

```
JAR/WAR/EAR的联系与区别
```

```
关于beeline:　beeline 是去调用hive的，　我们不采用直接cli模式，　也不采用jdbc的方法，　而采用beeline.
```

```
Hive与Hbase的联系与区别：
  Apache Hive是一个构建在Hadoop基础设施之上的数据仓库。通过Hive可以使用HQL语言查询存放在HDFS上的数据。HQL是一种类SQL语言，这种语言最终被转化为Map/Reduce. 虽然Hive提供了SQL查询功能，但是Hive不能够进行交互查询--因为它只能够在Haoop上批量的执行Hadoop。

  Apache HBase是一种Key/Value系统，它运行在HDFS之上。和Hive不一样，Hbase的能够在它的数据库上实时运行，而不是运行MapReduce任务。Hive被分区为表格，表格又被进一步分割为列簇。列簇必须使用schema定义，列簇将某一类型列集合起来（列不要求schema定义）。例如，“message”列簇可能包含：“to”, ”from” “date”, “subject”, 和”body”. 每一个 key/value对在Hbase中被定义为一个cell，每一个key由row-key，列簇、列和时间戳。在Hbase中，行是key/value映射的集合，这个映射通过row-key来唯一标识。Hbase利用Hadoop的基础设施，可以利用通用的设备进行水平的扩展。
```

```
beeline -u jdbc:hive2://127.0.0.1:10000/default -n hadoop
```

```
Inceptor算是数据库的功能层，　将下层的分布式存储系统（分布式数据库）的功能封装成接口（JDBC, SQL客户端，CLI等形式提供给用户)，　之后可能会对SQL进行编译优化等等，并与数据库存储引擎进行对接。
HyperBase算是数据库的存储引擎，需要解决分布式数据库的种种设计问题（分布式存储系统的各种问题：高可用，一致性，可扩展性，性能等), 参考OceanBase：提供了RootServer解决元数据存储问题，ChunkServer存储基线数据，UpdateServer在内存种存储增量数据，MergeServer解决用户的请求，将数据进行合并等操作。
当然:Inceptor似乎不仅仅支持分布式数据库的操作，　还支持其他的分布式存储系统的操作，　比如键值系统|分布式文件系统等。
```
