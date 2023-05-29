#include "mainwindow.h"

#include <QApplication>
#include<geometry.h>
#include<rectangle.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //测试：
    Rectangle rect;
    // 设置边框颜色，弹出颜色盘选择颜色
    rect.setBorderColor();
    // 设置填充颜色，弹出颜色盘选择颜色
    rect.setFillColor();
    rect.draw();

    return a.exec();
}
