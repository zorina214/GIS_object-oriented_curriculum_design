#include "sector.h"
#include "point.h"

Sector::Sector()
{
    // 初始化属性
    center = Point(0, 0);
    radius = 0.0;
    startAngle = 0.0;
    endAngle = 0.0;
}

Sector::~Sector()
{
    // 析构函数的实现（如果需要）
}

void Sector::draw()
{
    // 绘制扇形的实现
    // 使用存储的属性进行绘制操作
}

void Sector::setCenter(const Point& center)
{
    // 设置扇形的圆心坐标
    this->center = center;
}

Point Sector::getCenter() const
{
    // 获取扇形的圆心坐标
    return center;
}

void Sector::setRadius(double radius)
{
    // 设置扇形的半径
    this->radius = radius;
}

double Sector::getRadius() const
{
    // 获取扇形的半径
    return radius;
}

void Sector::setStartAngle(double startAngle)
{
    // 设置扇形的起始角度
    this->startAngle = startAngle;
}

void Sector::setEndAngle(double endAngle)
{
    // 设置扇形的结束角度
    this->endAngle = endAngle;
}

double Sector::getStartAngle() const
{
    // 获取扇形的起始角度
    return startAngle;
}

double Sector::getEndAngle() const
{
    // 获取扇形的结束角度
    return endAngle;
}
