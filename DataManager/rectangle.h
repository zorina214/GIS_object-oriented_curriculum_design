#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geometry.h"
#include "point.h"


class Rectangle :public Geometry
{
public:
      Rectangle();
      Rectangle(const Point& position, double width, double height);
      ~Rectangle();
      void draw() override;

      // 设置矩形的位置和尺寸
      void setPosition(const Point& position);
      void setSize(double width, double height);

      // 获取矩形的位置和尺寸
      Point getPosition() const;
      double getWidth() const;
      double getHeight() const;

      // 计算矩形的面积和周长
      double calculateArea() const;
      double calculatePerimeter() const;

  private:
      Point position;  // 矩形的位置（左上角坐标）
      double width;      // 矩形的宽度
      double height;     // 矩形的高度
};

#endif // RECTANGLE_H
