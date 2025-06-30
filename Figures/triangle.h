#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"
#include <QPolygon>

class Triangle : public Point {
public:
    Triangle(int x, int y, QColor color = Qt::black)
        : Point(x, y, color) {}

    void draw(QPainter* painter) override {
        painter->setBrush(color);
        QPolygon polygon;
        polygon << QPoint(position.x(), position.y() - 30)
                << QPoint(position.x() - 30, position.y() + 30)
                << QPoint(position.x() + 30, position.y() + 30);
        painter->drawPolygon(polygon);
    }
};

#endif
