#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle : public Point {
public:
    Circle(int x, int y, QColor color = Qt::black)
        : Point(x, y, color) {}

    void draw(QPainter* painter) override {
        painter->setBrush(color);
        painter->drawEllipse(position, 30, 30);
    }
};

#endif
