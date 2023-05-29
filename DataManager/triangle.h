#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"geometry.h"
#include"point.h"

class Triangle:public Geometry
{
public:
    Triangle();
    ~Triangle();
    void draw() override;

    // 设置三角形的顶点坐标
    void setVertices(const Point& vertex1, const Point& vertex2, const Point& vertex3);

    // 获取三角形的顶点坐标
    Point getVertex1() const;
    Point getVertex2() const;
    Point getVertex3() const;

    // 计算三角形的面积和周长
    double calculateArea() const;
    double calculatePerimeter() const;

private:
    Point vertex1;  // 三角形的第一个顶点
    Point vertex2;  // 三角形的第二个顶点
    Point vertex3;  // 三角形的第三个顶点
};

#endif // TRIANGLE_H
