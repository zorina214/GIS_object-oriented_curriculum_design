#ifndef POLYLINE_H
#define POLYLINE_H

#include "geometry.h"
#include "point.h"

class Polyline:public Geometry
{
public:
    Polyline();
    ~Polyline();
    void draw() override;

    // 添加一个顶点到折线
    void addVertex(const Point& vertex);

    // 获取折线的顶点数量
    int getVertexCount() const;

    // 获取指定索引处的顶点
    Point getVertex(int index) const;

    //获取所有顶点容器
    QVector<Point> getVector(const Polyline p);


private:
    QVector<Point> vertices; // 存储折线的顶点
};

#endif // POLYLINE_H
