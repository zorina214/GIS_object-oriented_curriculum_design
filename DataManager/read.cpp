#include "read.h"
#include <QString>
#include <QException>
#include "multgeometry.h"

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

ShapeFile::ShapeFile(const QString &fname)
{
    m_ifs.setFileName(fname);
    m_ifs.open(QIODevice::ReadOnly);//在QT中打开文件默认是二进制
    m_pos = 100; //文件头长100
}

int ShapeFile::GetShapeType()
{
    if (!m_ifs.isOpen()) return -1;
    m_ifs.seek(32);
    int type;
    //读取类型编号，付给type
    m_ifs.read((char*)(&type), 4);
    return type;
}
//获取一个点
int ShapeFile::GetShape(Point *pt)
{
    //移到内容
    m_ifs.seek(m_pos + 4);
    int len;
    m_ifs.read((char*)&len, 4);
    len = Big_To_Little(len) * 2;
    //起始位置
    char* ptBuf = new char[len];
    m_ifs.read(ptBuf, len);
    //int* start = (int*)(ptBuf + 4);
    double* pnts = (double*)(ptBuf + 4);
    pt->setCoordinates(pnts[0],pnts[1]);

    return 1;
}

//获取一条线
int ShapeFile::GetShape(Polyline *pt)
{
    //移到104
    m_ifs.seek(m_pos + 4);
    //读取长度
    int len;
    m_ifs.read((char*)(&len), 4);
    len = Big_To_Little(len) * 2;
    //按照长度建立字符数组
    char* ptBuf = new char[len];
    m_ifs.read(ptBuf, len);
    //折线数量（点对）
    int partNum = *(int*)(ptBuf + 36);
    //点的数量
    int pointNum = *(int*)(ptBuf + 40);
    //内容开始的位置
    int* start = (int*)(ptBuf + 44);
    double* pnts = (double*)(ptBuf + 44 + partNum * 4);//每一条记录的位置
    for (int i = 0; i < partNum; i++)
    {
        int end = (i == partNum - 1) ? pointNum : start[i + 1];
        QVector<double> tmp;
        for (int j = start[i]; j < end; j++)
        {
            //将数值对压入容器
            tmp.push_back(pnts[2 * j]);
            tmp.push_back(pnts[2 * j + 1]);
        }
        //将tmp中的数值对应生成点->存在线类中
        for(int k=0;k<tmp.size();k++)
        {
            Point tt(tmp[k],tmp[k+1]);
            pt->addVertex(tt);
        }
        //多个直线段存入多线容器
        //pt->Getmline().push_back(tmpline);
    }
    delete[]ptBuf;
    return 1;
}

//获取一个多边形
int ShapeFile::GetShape(Polygon *pt)
{
    //移到104
    m_ifs.seek(m_pos + 4);
    //读取长度
    int len;
    m_ifs.read((char*)&len, 4);
    len = Big_To_Little(len) * 2;
    //按照长度建立字符数组
    char* ptBuf = new char[len];
    m_ifs.read(ptBuf, len);
    //折线数量（点对）
    int partNum = *(int*)(ptBuf + 36);
    //点的数量
    int pointNum = *(int*)(ptBuf + 40);
    //内容开始
    int* start = (int*)(ptBuf + 44);
    double* pnts = (double*)(ptBuf + 44 + partNum * 4);
    for (int i = 0; i < partNum; i++)
    {
        int end = (i == partNum - 1) ? pointNum : start[i + 1];
        QVector<double> tmp;
        for (int j = start[i]; j < end; j++)
        {
            tmp.push_back(pnts[2 * j]);
            tmp.push_back(pnts[2 * j + 1]);
        }
        //将tmp中的数值对应生成点->存在多边形类中
        for(int k=0;k<tmp.size();k++)
        {
            Point tt(tmp[k],tmp[k+1]);
            pt->addVertex(tt);
        }
    }
    delete[]ptBuf;
    return 1;
}

bool ShapeFile::Next()
{

    if (m_ifs.atEnd() || !m_ifs.isReadable())
    {
        return false;
    }

    int recordLength;
    m_ifs.seek(m_pos + 4);
    m_ifs.read((char*)(&recordLength), 4);
    recordLength = Big_To_Little(recordLength) * 2;

    m_pos += 8 + recordLength;
    m_ifs.seek(m_pos);

    return !m_ifs.atEnd();
}



//地理数据类实现
//判断属于那个类别，新建对应的文件读取对象
Geodata::Geodata(const char *fname)
{
    QString str = QString::fromStdString(fname);
    if (str.endsWith(".shp", Qt::CaseInsensitive))
        m_file = new ShapeFile(fname);
    else if (str.endsWith(".txt", Qt::CaseInsensitive))
        m_file = new TextFile(fname);
}

//获取几何类型
int Geodata::GetShapeType() const
{
    //转到具体类型中实现
    return m_file->GetShapeType();
}

//获取图形，调入各类型图形的GetShape函数
Geometry *Geodata::GetShape()
{
    int type = m_file->GetShapeType();
    //SHP
    if (type == 3)
    {
        m_file->GetShape(&m_curPolyLine);
        return &m_curPolyLine;
    }
    else if (type == 1)
    {
        m_file->GetShape(&m_curPoint);
        return &m_curPoint;
    }
    else if (type == 5)
    {
        m_file->GetShape(&m_curPolygon);
        return &m_curPolygon;
    }
    //Text
    else if (type == 2)
    {
        m_file->GetShape(&m_curCircle);
        return &m_curCircle;
    }
    else if (type == 4)
    {
        m_file->GetShape(&m_curRectangle);
        return &m_curRectangle;
    }
    else if (type == 6)
    {
        m_file->GetShape(&m_curTriangle);
        return &m_curTriangle;
    }
    else {
        return NULL;
    }
}

//读取下一个数据
bool Geodata::Next()
{
    if (!m_file->Next())
    {
        return false;
    }
    else
    {
        return true;
    }
}
