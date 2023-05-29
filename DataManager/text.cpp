#include "text.h"

#include <QPainter>

Text::Text()
{
    // 初始化文本内容、位置和字体大小
    text = "";
    position = Point(0, 0);
    fontSize = 12;
}

Text::~Text()
{
    // 析构函数的实现（如果需要）
}

void Text::draw()
{
//    // 绘制文本的实现
//    QPainter painter;
//    // 设置绘制的字体大小
//    QFont font;
//    font.setPointSize(fontSize);
//    painter.setFont(font);
//    // 绘制文本内容
//    painter.drawText(position.getX(), position.getY(), text);
}

void Text::setText(const QString& text)
{
    // 设置文本内容
    this->text = text;
}

QString Text::getText() const
{
    // 获取文本内容
    return text;
}

void Text::setPosition(const QPointF& position)
{
    // 设置文本位置
    this->position = Point(position.x(), position.y());
}

QPointF Text::getPosition() const
{
    // 获取文本位置
    return QPointF(position.getX(), position.getY());
}

void Text::setFontSize(int fontSize)
{
    // 设置文本字体大小
    this->fontSize = fontSize;
}

int Text::getFontSize() const
{
    // 获取文本字体大小
    return fontSize;
}

