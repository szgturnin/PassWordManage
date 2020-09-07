## 写一个最简化可用的工具需要了解的qml相关点

1. **Q_PROPERTY,Q_INVOKABLE作用是什么?**

2. **如何把C++类注册到Qml中，如何把C++对象注册到Qml中，C++如何使用Qml的对象?**

3. **C++和Qml之间的信号槽互联和互发?**

4. **建议:界面布局显示使用qml进行，逻辑部分使用C++完成，UI-Logic之间通过Qt的信号槽之间来完成。**

5. **Qml的语法规则简述,Qml之间进行信号槽连接的规则是什么？**

6. **Qml之间的组件和布局-(Designer),简单介绍**







### Q_PROPERTY作用是什么?

一个属性行为类似于类里面的数据成员，但是他是却可以通过**Meta-Object System**来访问。

>  定义：

```c++
Q_PROPERTY(type name
           
             (READ getFunction [WRITE setFunction] |
              MEMBER memberName [(READ getFunction |
                                  WRITE setFunction)])
           
             [RESET resetFunction]
             [NOTIFY notifySignal]
             [REVISION int]
             [DESIGNABLE bool]
             [SCRIPTABLE bool]
             [STORED bool]
             [USER bool]
             [CONSTANT]
             [FINAL])
```

> 解释:
>
> 1. 必须有一个read函数。它用来读取属性值。并且该返回值必须是该属性值的类型
> 2. 有一个可选的write函数。它用来设置属性值，它的返回值必须为void型，而起必须要含有一个参数。
> 3. 一个reset函数能够把property设置成其默认状态，它也是可选的。复位功能必须返回void，并且不带参数。
> 4. 一个NOTIFY信号是可选的 。如果定义，它提供了一个信号这个信号在值发生改变时会自动被触发。**这点在Qml信号槽关联编程中比较方便**
> 5. USER 属性 表面是否可以被用户所编辑
> 6. **CONST 设定属性是不可修改的 所以不能跟WRITE或者NOTIFY同时出现**
> 7. FINAL 表明该属性不会被派生类中重写
> 8. MEMBER 如果不存在READ的话，这个属性的定义必须要存在，用于成员变量的READ和WRITE函数
>
> ...



> **例子:**
>
> ```c++
> Q_PROPERTY(QString name READ readName WRITE setName NOTIFY nameChanged)
> ```
>
> 1. 定义一个name的变量，这个name是对qml来说的。
> 2. 需要定义和实现一个readName函数，QString readName();
> 3. 需要定义和实现一个setName函数，void setName(QString name);
> 4. 需要声明一个nameChanged信号
>
> 当name这个变量在qml中被读取的时候会自动触发readName函数。name变量被修改时，自动触发setName函数。注意：**nameChanged需要在setName中emit，否则该信号不会发出**

#### 总结:

1. Q_PROPERTY 规范了类中的属性需要哪些函数，在属性被设计的时候写好这个，会在编译的时候提示哪些没做。可以概览某个属性都有哪些读写属性和信号等参数。
2. 在Qml中调用该属性的时候，会自动的触发相关的函数和信号。



### Q_INVOKABLE作用是什么?

**C++对象注册到了Qml环境下，该类中的共有函数被Q_INVOKABLE 声明的，就可以在Qml环境下正常的调用了**

相同作用的另一种做法：把上面的共有函数放到public slots：下。



### 如何把C++类注册到Qml中，C++如何使用Qml的对象?

#### 如何把C++对象注册到Qml中



方法1：

```C++
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("xml",new WrXml);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    return app.exec();
 }
```



方法2：

```c++
int main(int argc, char *argv[])
{    
    QGuiApplication app(argc, argv);
    
	QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.rootContext()->setContextProperty("xml",new WrXml);//这个"xml"就代表了  WrXml这个new出来的对象。可以在qml中被使用
    viewer.setSource(QUrl("qrc:/main.qml"));
    
    return app.exec();
 } 
```



**之后在Qml环境下就可以全局使用xml这个对象。**

#### 如何把C++类注册到Qml中

```c++
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    qmlRegisterType<ColorMaker>("an.qt.ColorMaker", 1, 0, "ColorMaker");
    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/colorMaker/main.qml"));
    viewer.showExpanded();
 
    return app.exec();
}
```



#### C++如何使用Qml的对象?

