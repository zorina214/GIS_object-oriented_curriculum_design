#ifndef READ_H
#define READ_H
#include <QString>
#include <QFile>
#include "polyline.h"
#include "point.h"
#include "polygon.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "multgeometry.h"

//抽象类接口
class Read
{
public:
    virtual ~Read();
    virtual void ReadPoint(QString& filePath, MultPoint* p) = 0;
    virtual void ReadPolyline(QString& filePath, MultPoint* p) = 0;
    virtual void ReadPolygon(QString& filePath, MultPoint* p) = 0;
};


class ShpRead:public Read
{
public:
    ~ShpRead();
    virtual void ReadPoint(QString& filePath, MultPoint* p)override;
    virtual void ReadPolyline(QString& filePath, MultPoint* p)override;
    virtual void ReadPolygon(QString& filePath, MultPoint* p)override;
};

class TxtRead:public Read
{
public:
    ~TxtRead();
};

class TifRead:public Read
{
public:
    ~TifRead();
};


//读取格式的基类，包含读取类型与读取形状信息
class GeoFormat
{
public:
    virtual int GetShapeType() = 0;
    virtual int GetShape(Polyline* pt) = 0;
    virtual int GetShape(Polygon* pt) = 0;
    virtual int GetShape(Point* pt) = 0;

    virtual int GetShape(Circle* pt) = 0;
    virtual int GetShape(Rectangle* pt) = 0;
    virtual int GetShape(Triangle* pt) = 0;

    //进行下一个对象的读取
    virtual bool Next() = 0;
};

//ShapeFile格式，继承格式基类
class ShapeFile : public GeoFormat
{
public:
    ShapeFile(const QString& fname);

    //读取几何类型（卸载文件头中）
    int GetShapeType()override;
    //获取一条折线
    int GetShape(Polyline* pt)override;
    //获取一个点
    int GetShape(Point* pt)override;
    //获取一个多边形
    int GetShape(Polygon* pt)override;
    //读取下一个
    bool Next()override;

    virtual int GetShape(Circle* pt)override{return 0;}
    virtual int GetShape(Rectangle* pt)override{return 0;}
    virtual int GetShape(Triangle* pt)override{return 0;}

private:
    QFile m_ifs;//文件打开对象
    int m_pos;//shp文件的文件头长度
};

//TxtFile格式，继承格式基类
class TextFile:public GeoFormat
{
private:
    QFile m_ifs;
public:
    //构造函数，转入各自的类别中进行构造
    TextFile(const char* fname);
    //读取第一个string：几何类型
    int GetShapeType()override;
    //读取圆的几何信息
    int GetShape(Circle* pt)override;//未实现
    //读取矩形
    int GetShape(Rectangle* pt)override;//未实现
    //读取三角形
    int GetShape(Triangle* pt)override;//未实现
    bool Next()override;//未实现

    virtual int GetShape(Polyline* pt)override { return 0; }
    virtual int GetShape(Polygon* pt)override { return 0; }
    virtual int GetShape(Point* pt)override { return 0; }
};

//地理数据类
class Geodata
{
public:
    Geodata(const char* fname);//判断属于那个类别，新建对应的文件读取对象
    int GetShapeType() const;//获取几何类型
    Geometry* GetShape();//获取图形，调用各类型图形的GetShape函数
    bool Next();//读取文件中的下一个对象

private:
    GeoFormat* m_file;
    Polyline   m_curPolyLine;
    Point   m_curPoint;
    Polygon   m_curPolygon;

    Circle   m_curCircle;
    Rectangle   m_curRectangle;
    Triangle   m_curTriangle;
};

#endif // READ_H
