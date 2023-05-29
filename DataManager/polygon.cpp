#include "polygon.h"
#include "point.h"

Polygon::Polygon()
{
    // 构造函数的实现，多边形中的点可以在add等函数中添加
}

Polygon::~Polygon()
{
    // 析构函数的实现
}

void Polygon::draw()
{
    // 绘制多边形的实现
    // 在这里编写绘制多边形的代码逻辑
}

void Polygon::addVertex(const Point& vertex)
{
    // 添加一个顶点到多边形的实现
    vertices.append(vertex);
}

int Polygon::getVertexCount() const
{
    // 获取多边形的顶点数量的实现
    return vertices.size();
}

Point Polygon::getVertex(int index) const
{
    // 获取指定索引处的顶点的实现
    if (index >= 0 && index < vertices.size()) {
        return vertices.at(index);
    }
    return Point(); // 返回一个空的 QPointF，表示索引无效
}
