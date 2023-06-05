#include "point.h"


Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    // 析构函数的实现（如果需要）
}

void Point::draw()
{
    // 绘制点的实现

}

void Point::setCoordinates(double x, double y)
{
    // 设置点的坐标
    this->x = x;
    this->y = y;
}

double Point::getX()
{
    // 获取点的 x 坐标
    return x;
}

double Point::getY()
{
    // 获取点的 y 坐标
    return y;
}
