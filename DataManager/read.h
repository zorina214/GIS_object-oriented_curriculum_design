#ifndef READ_H
#define READ_H
#include<QString>


//读取shapefile文件必备的转换函数
/*1.Big2Little 函数
这个函数用于将大端字节序的整数转换成小端字节序的整数。
这个函数在读取 Shapefile 格式数据时会用到，因为 Shapefile
数据是按照小端字节序存储的，所以需要将读取到的数据进行转换*/
int Big_To_Little(int a)
{
    char *pt = (char*)&a; // 将整型指针强转成字符型指针，以字节为单位进行处理
    int b;
    char *pt0= (char*)&b;// 将整数b的地址强制转换为字符型指针
    pt0[0] = pt[3];// 将a的第4个字节赋值给b的第1个字节，即将a的高字节放到b的低字节
    pt0[1] = pt[2];// 同上，进行reverse就实现了大小端的转换
    pt0[2] = pt[1];
    pt0[3] = pt[0];
    return b; //最后返回一个整数b
}




//抽象类接口
class Read
{
public:
    virtual ~Read();
    virtual void read(const QString& filePath) = 0;

    /*toWKT 的函数，用于将几何对象转换成 WKT 格式的字符串。
    其中，WKT（Well-known text）是一种用于描述空间几何对象的文本格式。
    PolyLineRead、PolygonRead、PointRead 类等可以继承 Read，从而统一了接口，方便使用*/
    //方便输出到控制台或文件中，以供后续的使用
    virtual QString toWKT() = 0;//这个函数只是为了将目前这个类中的已经有的内容转化成WKT格式的string进行展示，不是从shp中读东西的函数！
    virtual QString GetType() = 0;//可以方便获取对象的type
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


#endif // READ_H
