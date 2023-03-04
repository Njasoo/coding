#include "mywidget.h"
#include <QApplication>//包含一个应用程序类的头文件

//main程序入口 argc命令行变量数量 argv命令变量的数组
int main(int argc, char *argv[])
{
    //a:应用程序对象，在qt中，应用程序对象有且仅有一个
    QApplication a(argc, argv);
    //w:窗口对象 myWidget父类 -> QWidget
    myWidget w;
    //调用了show()方法来显示窗口，窗口默认不会显示
    w.show();

    //让应用程序对象进入消息循环，类似死循环
    return a.exec();
}
