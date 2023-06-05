#ifndef MULTGEOMETRY_H
#define MULTGEOMETRY_H
#include "geometry.h"
#include "polyline.h"
#include "polygon.h"
#include "point.h"

//多点类
class MultPoint:Geometry
{
public:
    void draw() override;

    int GetNum(){return num;}
    QVector<Point> Getmpoint(){return mpoint;}

private:
    int num;
    QVector<Point> mpoint;
};


//多线类
class MultPolyline:Geometry
{
public:
    void draw() override;

    int GetNum(){return num;}
    QVector<Polyline> Getmline(){return mline;}

private:
    int num;
    QVector<Polyline> mline;
};

//多面类
class MultPolygon:Geometry
{
public:
    void draw() override;

    int GetNum(){return num;}
    QVector<Polygon> Getmpolygon(){return mpolygon;}

private:
    int num;
    QVector<Polygon> mpolygon;
};

#endif // MULTGEOMETRY_H
