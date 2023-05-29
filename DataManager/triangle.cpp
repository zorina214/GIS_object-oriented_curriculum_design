#include "triangle.h"

Triangle::Triangle()
{
    // 初始化顶点坐标
    vertex1 = Point(0, 0);
    vertex2 = Point(0, 0);
    vertex3 = Point(0, 0);
}

Triangle::~Triangle()
{
    // 析构函数的实现（如果需要）
}

void Triangle::draw()
{
    // 绘制三角形的实现
}

void Triangle::setVertices(const Point& vertex1, const Point& vertex2, const Point& vertex3)
{
    // 设置三角形的顶点坐标
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
    this->vertex3 = vertex3;
}

Point Triangle::getVertex1() const
{
    // 获取三角形的第一个顶点坐标
    return vertex1;
}

Point Triangle::getVertex2() const
{
    // 获取三角形的第二个顶点坐标
    return vertex2;
}

Point Triangle::getVertex3() const
{
    // 获取三角形的第三个顶点坐标
    return vertex3;
}

double Triangle::calculateArea() const
{
    // 计算三角形的面积
    // 在这里根据顶点坐标计算三角形面积的具体算法
    // 返回计算得到的面积值
    return 0.0;
}

double Triangle::calculatePerimeter() const
{
    // 计算三角形的周长
    // 在这里根据顶点坐标计算三角形周长的具体算法
    // 返回计算得到的周长值
    return 0.0;
}
