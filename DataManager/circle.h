#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometry.h"
#include "point.h"

class Circle:public Geometry
{
public:
    Circle();
    ~Circle();

    // 绘制圆形图元
    void draw() override;

    // 设置圆心的坐标
    void setCenter(const Point& center);

    // 获取圆心的坐标
    Point getCenter() const;

    // 设置圆的半径
    void setRadius(double radius);

    // 获取圆的半径
    double getRadius() const;

private:
    Point center;   // 圆心坐标
    double radius;  // 圆的半径
};

#endif // CIRCLE_H
