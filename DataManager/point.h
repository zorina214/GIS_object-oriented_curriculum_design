#ifndef POINT_H
#define POINT_H

#include<geometry.h>


class Point:public Geometry
{
public:
    Point();
    Point(double x, double y);
    ~Point();
    void draw() override;

    // 设置点的坐标
    void setCoordinates(double x, double y);

    // 获取点的x坐标
    double getX();

    // 获取点的y坐标
    double getY();

private:
    double x;   // x坐标
    double y;   // y坐标
};

#endif // POINT_H
