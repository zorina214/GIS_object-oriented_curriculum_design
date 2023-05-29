#ifndef TEXT_H
#define TEXT_H

#include"geometry.h"
#include"point.h"

class Text:public Geometry
{
public:
    Text();
    ~Text();
    void draw() override;

    // 设置文本内容
    void setText(const QString& text);

    // 获取文本内容
    QString getText() const;

    // 设置文本位置
    void setPosition(const QPointF& position);

    // 获取文本位置
    QPointF getPosition() const;

    // 设置文本字体大小
    void setFontSize(int fontSize);

    // 获取文本字体大小
    int getFontSize() const;

private:
    QString text;        // 文本内容
    Point position;    // 文本位置（矩形框左上角）
    int fontSize;        // 文本字体大小
};

#endif // TEXT_H
