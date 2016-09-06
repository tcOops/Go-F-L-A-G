##Java Process

```
implement 与 extends的区别：
这一点很明显：
  1. implement是用来继承某个接口， 而接口中定义的方法是必须要实现的。 接口的意义便在于，为类抽象出共有的行为。
  2. extends关注的是OOP里面的继承关系， 表示子类对父类的一种扩展。 类的意义在于，将相近的东西进行归类，便于管理。

```

```
要Array.sort排序必须显式实现Comparable接口(java是strong-type语言)， 这一点类似于C++中要重载<运算符来实现sort排序一样，
但是java并没有运算符重载这回事。
```

```
Object类中有clone方法， 但是要实现deep-copy，以及使用clone时， 还是要实现Cloneable接口
```

```
@override, 相当于一种注解(区别于wrapper,嵌套函数)，告诉编译器该方法只是一个重写方法，
需要区别重写(都不能变)与重载(参数类型，个数或者返回值类型可以变)。
@interface
```

```
Maven包依赖管理， 类似于pip或者npm, 使用pom文件来说明需要哪些外界的包依赖(至于jdk自身的包会自动导入)，
如何将本地的包全LAN共享，还需要探究 (在~/.m2文件夹下添入一个settings.xml的配置文件)
```

```
Map, HashMap, HashTable, HashSet的区别:
 1.Hashtable继承自Dictionary类，而HashMap继承自AbstractMap类, 但二者都实现了Map接口。
 2.HashTable是Sync的，所以线程安全， 而HashMap并不是。
```

```
Java语言内置的语言级同步原语: synchronized
```
可参考: [http://www.cnblogs.com/devinzhang/archive/2011/12/14/2287675.html](http://www.cnblogs.com/devinzhang/archive/2011/12/14/2287675.html)
