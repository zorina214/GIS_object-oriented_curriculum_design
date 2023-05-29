#include "circle.h"
#include "point.h"

Circle::Circle()
{
    // 初始化圆心和半径
    center = Point(0, 0);
    radius = 0.0;
}

Circle::~Circle()
{
    // 析构函数的实现（如果需要）
}

void Circle::draw()
{
    // 绘制圆形图元的实现
}

void Circle::setCenter(const Point& center)
{
    // 设置圆心的坐标
    this->center = center;
}

Point Circle::getCenter() const
{
    // 获取圆心的坐标
    return center;
}

void Circle::setRadius(double radius)
{
    // 设置圆的半径
    this->radius = radius;
}

double Circle::getRadius() const
{
    // 获取圆的半径
    return radius;
}
