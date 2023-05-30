#include "read.h"
#include <QString>


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
    m_ifs.read(reinterpret_cast<char*>(&type), 4);
    return type;
}

int ShapeFile::GetShape(Polyline *pt)
{
    //移到104
    m_ifs.seek(m_pos + 4);
    //读取长度
    int len;
    m_ifs.read(reinterpret_cast<char*>(&len), 4);
    len = Big_To_Little(len) * 2;
    //按照长度建立字符数组
    QByteArray ptBuf = m_ifs.read(len);
    //折线数量（点对）
    int partNum = *reinterpret_cast<int*>(ptBuf.data() + 36);
    //点的数量
    int pointNum = *reinterpret_cast<int*>(ptBuf.data() + 40);
    //内容开始的位置
    int* start = reinterpret_cast<int*>(ptBuf.data() + 44);
    double* pnts = reinterpret_cast<double*>(ptBuf.data() + 44 + partNum * 4); //每一条记录的位置
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
        //将tmp中的数值对应生成点
        for(int k=0;k<tmp.size();k++)
        {
            Point tt(tmp[k],tmp[k+1]);
            pt->getVector(*pt).push_back(tt);
        }
        //多个直线段（数值对）压入折线容器
        pt->m_Parts.push_back(tmp);
    }
    return 1;
}



