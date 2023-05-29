#ifndef POLYGON_H
#define POLYGON_H

#include "geometry.h"
#include "point.h"

class Polygon:public Geometry
{
public:
    Polygon();
    ~Polygon();
    void draw() override;

    // 添加一个顶点到多边形
    void addVertex(const Point& vertex);

    // 获取多边形的顶点数量
    int getVertexCount() const;

    // 获取指定索引处的顶点
    Point getVertex(int index) const;

private:
    QVector<Point> vertices; // 存储多边形的顶点
};

#endif // POLYGON_H
