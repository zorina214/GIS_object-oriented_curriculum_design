#ifndef STORAGE_H
#define STORAGE_H
#include"geometry.h"

class Storage
{
public:
    virtual ~Storage() {}

    // 从存储介质中读取数据并还原为几何对象和样式对象
    //virtual void load(Geometry& geometry, Style& style) = 0;

    // 将几何对象和样式对象保存到存储介质中
    virtual void save(const Geometry& geometry, const Style& style) = 0;
};

class ShpStorage : public Storage
{
public:
    ~ShpStorage();
    // 将几何对象和样式对象的状态保存到shp文件中
    void save(const Geometry& geometry, const Style& style) override;
};

class TxtStorage : public Storage
{
public:
    ~TxtStorage();
    // 将几何对象和样式对象的状态保存到txt文件中
    void save(const Geometry& geometry, const Style& style) override;
};

class TifStorage : public Storage
{
public:
    ~TifStorage();
    // 将几何对象和样式对象的状态保存到tif文件中
    void save(const Geometry& geometry, const Style& style) override;
};

class DbfStorage : public Storage
{
public:
    ~DbfStorage();
    // 将几何对象和样式对象的状态保存到数据库中
    void save(const Geometry& geometry, const Style& style) override;
};

#endif // STORAGE_H
