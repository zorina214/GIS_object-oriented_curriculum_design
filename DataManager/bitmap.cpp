#include "bitmap.h"


Bitmap::Bitmap()
{

}
void Bitmap::setSize(int width, int height)
{
    // 删除旧的位图数据（如果存在）
    if (pixels != nullptr)
    {
        for (int i = 0; i < this->width; i++)
            delete[] pixels[i];
        delete[] pixels;
    }

    // 设置新的宽度和高度
    this->width = width;
    this->height = height;

    // 创建新的位图数据
    pixels = new bool*[height];
    for (int i = 0; i < height; i++)
    {
        pixels[i] = new bool[width];
        // 初始化像素值，默认为 false
        for (int j = 0; j < width; j++)
        {
            pixels[i][j] = false;
        }
    }
}

void Bitmap::setPixel(int x, int y, bool value)
{
    // 检查像素坐标是否在有效范围内
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        pixels[y][x] = value;
    }
}
