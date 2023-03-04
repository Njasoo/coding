#include "mywidget.h"
#include <QPushButton> // 按钮控件的头文件

//同名之间，源文件和头文件的切换 F4
//对齐 ctrl + i

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn=new QPushButton;
    btn->show();//show以顶层方式弹出窗口控件
    //让btn对象 依赖在 myWidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮
    QPushButton *btn2=new QPushButton("second button",this); // (constext, parent)

    //move the second button
    btn2->move(200,200);
    // 重置窗口大小
    resize(600, 400);
}

myWidget::~myWidget()
{

}
