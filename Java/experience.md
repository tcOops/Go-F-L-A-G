##Java Process

```
要Array.sort排序必须显式实现Comparable接口(java是strong-type语言)， 这一点类似于C++中要重载<运算符来实现sort排序一样，
但是java并没有运算符重载这回事。
```

```
Object类中有clone方法， 但是要实现deep-copy，以及使用clone时， 还是要实现Cloneable接口
```

```
@override, 相当于一种注解(区别于wrapper,嵌套函数)，
@interface
```

```
Maven包依赖管理， 类似于pip或者npm, 使用pom文件来说明需要哪些外界的包依赖(至于jdk自身的包会自动导入)，
如何将本地的包全LAN共享，还需要探究
```
