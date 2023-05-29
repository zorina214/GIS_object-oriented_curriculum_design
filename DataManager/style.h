#ifndef STYLE_H
#define STYLE_H

#include <QColor>
#include <QPixmap>
#include <QVector>

class Style
{
public:
    Style();
    ~Style();
    // 设置边框颜色
    void setBorderColor(const QColor& color);

    // 获取边框颜色
    QColor getBorderColor() const;

    // 设置填充颜色
    void setFillColor(const QColor& color);

    // 获取填充颜色
    QColor getFillColor() const;

    // 添加填充图案
    void addFillPattern(const QPixmap& pattern);

    // 获取填充图案数量
    int getFillPatternCount() const;

    // 获取指定索引处的填充图案
    QPixmap getFillPattern(int index) const;

private:
    QColor borderColor;            // 边框颜色
    QColor fillColor;              // 填充颜色
    QVector<QPixmap> fillPatterns; // 填充图案容器
};

#endif // STYLE_H
