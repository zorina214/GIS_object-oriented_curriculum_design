#ifndef READ_H
#define READ_H
#include <QString>
#include <QFile>
#include "polyline.h"
#include "point.h"
#include "polygon.h"


//抽象类接口
class Read
{
public:
    virtual ~Read();
    virtual void read(const QString& filePath) = 0;
};


class ShpRead:public Read
{
public:
    ~ShpRead();
    void read(const QString& filePath)override;

};

class TxtRead:public Read
{
public:
    ~TxtRead();
    void read(const QString& filePath)override;

};

class TifRead:public Read
{
public:
    ~TifRead();
    void read(const QString& filePath)override;
};


//读取格式的基类，包含读取类型与读取形状信息
class GeoFormat
{
public:
    virtual int GetShapeType() = 0;
    virtual int GetShape(Polyline* pt) = 0;
    virtual int GetShape(Polygon* pt) = 0;
    virtual int GetShape(Point* pt) = 0;
};

//ShapeFile格式，继承格式基类
class ShapeFile : public GeoFormat
{
public:
    ShapeFile(const QString& fname);

    //读取几何类型（卸载文件头中）
    int GetShapeType()override;

    //获取折线
    int GetShape(Polyline* pt)override;

    //获取点
    int GetShape(Point* pt)override;

    //获取多边形
    int GetShape(Polygon* pt)override;

private:
    QFile m_ifs;
    int m_pos;
};

#endif // READ_H
