#ifndef SQUARE_H
#define SQUARE_H

#include "point.h"

class Square : public Point {
public:
    Square(int x, int y, QColor color = Qt::black)
        : Point(x, y, color) {}

    void draw(QPainter* painter) override {
        painter->setBrush(color);
        painter->drawRect(position.x() - 30, position.y() - 30, 60, 60);
    }
};

#endif
