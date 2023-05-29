#ifndef SECTOR_H
#define SECTOR_H

#include"geometry.h"
#include "point.h"

class Sector:public Geometry
{
private:
    Point center;       // 圆心坐标
    double radius;        // 半径
    double startAngle;    // 起始角度
    double endAngle;      // 结束角度

public:
    Sector();
    ~Sector();
    void draw() override;

    // 设置扇形的圆心坐标
    void setCenter(const Point& center);

    // 获取扇形的圆心坐标
    Point getCenter() const;

    // 设置扇形的半径
    void setRadius(double radius);

    // 获取扇形的半径
    double getRadius() const;

    // 设置扇形的起始角度和结束角度（以度为单位）
    void setStartAngle(double startAngle);
    void setEndAngle(double endAngle);

    // 获取扇形的起始角度和结束角度（以度为单位）
    double getStartAngle() const;
    double getEndAngle() const;
};

#endif // SECTOR_H
