#ifndef FACTORY_H
#define FACTORY_H

#include"geometry.h"
#include"bitmap.h"
#include"circle.h"
#include"rectangle.h"

//工厂类
class Factory
{
public:
    virtual ~Factory(){}
    //纯虚函数，用于创建具体的几何图元对象
    virtual Geometry* create()=0;
};

// BitmapFactory（圆的具体工厂类）
class BitmapFactory : public Factory {
public:
    Geometry* create() override{}
};


// CircleFactory（圆的具体工厂类）
class CircleFactory : public Factory {
public:
    Geometry* create() override
    {
        return new Circle(); // 创建圆对象并返回
    }
};

// PointFactory（圆的具体工厂类）
class PointFactory : public Factory {
public:
    Geometry* create() override{}
};

// PolygonFactory（圆的具体工厂类）
class PolygonFactory : public Factory {
public:
    Geometry* create() override{}
};

// PolylineFactory（圆的具体工厂类）
class PolylineFactory : public Factory {
public:
    Geometry* create() override{}
};

// RectangleFactory（矩形的具体工厂类）
class RectangleFactory : public Factory {
public:
    Geometry* create() override
    {
        return new Rectangle(); // 创建矩形对象并返回
    }
};

// SectorFactory（圆的具体工厂类）
class SectorFactory : public Factory {
public:
    Geometry* create() override{}
};

// TextFactory（圆的具体工厂类）
class TextFactory : public Factory {
public:
    Geometry* create() override{}
};

// TriangleFactory（圆的具体工厂类）
class TriangleFactory : public Factory {
public:
    Geometry* create() override{}
};


#endif // FACTORY_H
