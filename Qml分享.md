## 写一个最简化可用的工具需要了解的qml相关点

1. **Q_PROPERTY,Q_INVOKABLE作用是什么?**
2. **如何把C++类注册到Qml中，如何把C++对象注册到Qml中，C++如何使用Qml的对象?**
3. **C++和Qml之间的信号槽互联和互发?**
4. **Qml的语法规则简述**
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



### 如何把C++类注册到Qml中，如何把C++对象注册到Qml中,C++如何使用Qml的对象?

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
qmlRegisterType<WrXml>("szg.test.customClassToQml", 1, 0, "WrXml");
```

> 在Qml中导入并且使用

```javascript
import szg.test.customClassToQml 1.0
```

之后就可以像使用Qml类型一样，使用这个注册的了C++对象。类型名为WrXml

##### Qt类枚举类型注册

> 上代码

```c++
class WrXml : public QObject
{
    Q_OBJECT
    Q_ENUMS(TESTENUM)
public:
    enum TESTENUM{
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE
    };
 }
```

**在Qml中就以以下形式使用就行了： 类型名.枚举值       （WrXml.ZERO）**

#### C++如何使用Qml的对象?

> 讨论这个情况，需要先讲述Qml文件加载的几种方式

1. **QQmlApplicationEngine加载QML**

查看帮助文档，可以看出QQmlApplicationEngine继承自QQmlEngine->QObject.    

这种方式属于QQmlApplicationEngine搭配Window(**Qml类型**)

下面是获取Qml对象的方式介绍：

```c++
QQmlApplicationEngine engine;
engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
QObject *root = NULL;
QList<QObject*> rootObjects=engine.rootObjects();
int count=rootObjects.size();
for(int i=0;i<count;i++)
{     
    if(rootObjects.at(i)->objectName()=="rootObject")
    {
        root = rootObjects.at(i);
        break;
    }
    qDebug()<<rootObjects.at(i)->objectName();
}
QObject *quitButton=root->findChild<QObject*>("quitButton");
QObject::connect(quitButton,SIGNAL(clicked()),&app,SLOT(quit()));
bool ret=QMetaObject::invokeMethod(quitButton,"click");
```



2. **QQuickView加载QML **

```c++
    QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);

    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

	auto styBtnObject=viewer.rootObject();
    qDebug()<<"rootObject name:"<<styBtnObject->objectName();
    QObject *btnObj=styBtnObject->findChild<QObject*>("quitButton");
    if(btnObj){
        qDebug()<<"finchild success";
        bool ret=QMetaObject::invokeMethod(btnObj,"click");
        qDebug()<<"clicked:"<<ret;
    }
```

QQuickView加载Qml的区别和上面的QQmlApplicationEngine加载Qml的区别是，上面的main.qml主题窗口类型是window。这里若要是想要正常的运作，需要把Window改成Rectangle。Rectangle是不支持在Qml里面设置窗口的标题的，可以在C++里面进行设置。

3. **QQuickWidget加载QML** 

```C++
	QQuickWidget *view = new QQuickWidget;
    view->setSource(QUrl::fromLocalFile("myqmlfile.qml"));
    view->show();
```



通过上述的3种方式，拿到了QMl的对象了。就可以通过元对象系统对该对象进行调用了。

### C++和Qml之间的信号槽互联和互发?

当在C++端拿到了Qml的对象后，就可以对该对象进行操作了。无论是调用对方的函数还是连接信号和槽

对于Qml，导入到Qml上下文的对象，可以全局使用，以Qml的方式连接信号和槽。

> C++端连接Qml对象的信号，和调用对方的函数

```c++
QObject *quitButton=root->findChild<QObject*>("quitButton");
QObject::connect(quitButton,SIGNAL(clicked()),&app,SLOT(quit()));
bool ret=QMetaObject::invokeMethod(quitButton,"click");
```



> Qml端连接C++的信号，和调用对方的函数

```c++
    function recvCPlusSig(){
        console.log("c++ sig connect");
    }
    function onNameChanged(){
        console.log("name changed");
        console.log(WrXml.ONE);
    }    
	Component.onCompleted: {
        xml.sigCPlus.connect(recvCPlusSig)//C++信号连接到了qml的函数中
        xml.nameChanged.connect(onNameChanged)
    }
```

调用的话，全局都可以。任意地方都可以使用注册的对象调用进入元对象系统的函数。

### Qml的语法规则简述

大体上就是javascript的语法规则。

阐述几个Qml特殊的地方:

```javascript
property alias
给.qml文件中的某些属性取一个别名，相当于该属性的引用。当该Qml文件作为组件给别的.Qml文件使用的时候，该别名可以被直接使用，相当于该组件对象的属性
```

```javascript
首字母大写的.qml文件，可以作为组件被别的.qml文件直接调用，调用方式如下：
Atest.qml
在Btest.qml中，直接使用Atest{}来使用即可，可以新增属性，若属性值和之前的重复，当下的属性覆盖之前的属性
```

```c++
Qml文件之间发送信号和槽函数的连接
使用 single 关键字进行信号的定义    ，例如 single sig()
发送信号直接  sig() 即等于C++的emit sig()

对于这个sig的信号，槽函数的写法：

```





### Qml之间的组件和布局-(Designer),简单介绍













对于Qml/Qt界面如何实现，参考网上资料的意见，总结如下：

Qml本身适合拿来完成纯界面展现，尤其是大型的界面，会比传统的widget要来的方便和美观。小型的工具，qml-designer和传统的widget的界面拖拽差不多。

**建议:界面布局显示使用qml进行，逻辑部分使用C++完成，然后把对象注册到qml中去,UI-Logic之间通过Qt的信号槽之间来完成。**

