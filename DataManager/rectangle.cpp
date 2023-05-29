#include "rectangle.h"

Rectangle::Rectangle(const Point &position, double width, double height)
{
    // 设置位置和尺寸
        this->position = position;
        this->width = width;
        this->height = height;
}

Rectangle::Rectangle()
{
    // 初始化位置和尺寸
    position = Point(0, 0);
    width = 0.0;
    height = 0.0;
}

Rectangle::~Rectangle()
{
    // 析构函数的实现（如果需要）
}

void Rectangle::draw()
{
    // 绘制矩形图元的实现
    // 使用位置和尺寸信息进行绘制操作
}

void Rectangle::setPosition(const Point& position)
{
    // 设置矩形的位置
    this->position = position;
}

void Rectangle::setSize(double width, double height)
{
    // 设置矩形的尺寸
    this->width = width;
    this->height = height;
}

Point Rectangle::getPosition() const
{
    // 获取矩形的位置
    return position;
}

double Rectangle::getWidth() const
{
    // 获取矩形的宽度
    return width;
}

double Rectangle::getHeight() const
{
    // 获取矩形的高度
    return height;
}

double Rectangle::calculateArea() const
{
    // 计算矩形的面积
    return width * height;
}

double Rectangle::calculatePerimeter() const
{
    // 计算矩形的周长
    return 2 * (width + height);
}
