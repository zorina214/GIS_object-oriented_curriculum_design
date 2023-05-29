#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <QWidget>
#include <QColorDialog>
#include <QString>
#include "style.h"

// Geometry（几何图元的抽象基类）
class Geometry
{
public:

    virtual ~Geometry();

    // 纯虚函数，用于绘制几何图元
    virtual void draw() = 0;


protected:
    Style style;
};

#endif // GEOMETRY_H




