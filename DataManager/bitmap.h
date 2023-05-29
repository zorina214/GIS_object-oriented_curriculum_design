#ifndef BITMAP_H
#define BITMAP_H

#include "geometry.h"

class Bitmap:public Geometry
{
public:
    Bitmap();
    ~Bitmap();
    void draw() override;

    // 设置位图的宽度和高度
    void setSize(int width, int height);

    // 设置位图的像素值
    void setPixel(int x, int y, bool value);

private:
    int width;        // 位图宽度
    int height;       // 位图高度
    bool** pixels;    // 存储位图像素的二维数组
};

#endif // BITMAP_H
