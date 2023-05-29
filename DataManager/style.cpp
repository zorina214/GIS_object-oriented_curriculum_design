#include "style.h"

Style::Style(){}
// 设置边框颜色
void Style::setBorderColor(const QColor& color)
{
    borderColor = color;
}

// 获取边框颜色
QColor Style::getBorderColor() const
{
    return borderColor;
}

// 设置填充颜色
void Style::setFillColor(const QColor& color)
{
    fillColor = color;
}

// 获取填充颜色
QColor Style::getFillColor() const
{
    return fillColor;
}

// 添加填充图案
void Style::addFillPattern(const QPixmap& pattern)
{
    fillPatterns.push_back(pattern);
}

// 获取填充图案数量
int Style::getFillPatternCount() const
{
    return fillPatterns.size();
}

// 获取指定索引处的填充图案
QPixmap Style::getFillPattern(int index) const
{
    if (index >= 0 && index < fillPatterns.size())
        return fillPatterns[index];
    else
        return QPixmap(); // 返回一个空的 QPixmap 对象表示无效图案
}
