#include "polyline.h"


Polyline::Polyline()
{
    // 构造函数的实现（如果有需要的初始化操作）
}

Polyline::~Polyline()
{
    // 析构函数的实现（如果有需要的清理操作）
}


void Polyline::addVertex(const Point& vertex)
{
    vertices.append(vertex);
}

int Polyline::getVertexCount() const
{
    return vertices.size();
}

Point Polyline::getVertex(int index) const
{
    if (index >= 0 && index < vertices.size())
        return vertices[index];
    else
        return Point(); // 返回一个默认构造的 Point 对象作为错误处理
}

QVector<Point> Polyline::getVector(const Polyline p)
{
    return p.vertices;
}
