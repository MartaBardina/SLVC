#ifndef POINT_H
#define POINT_H

#include <QColor>
#include <QPainter>
#include <QPoint>

class Point {
public:
    Point(int x, int y, QColor color = Qt::black)
        : position(x, y), color(color) {}

    virtual ~Point() {}

    void setPosition(int x, int y) {
        position.setX(x);
        position.setY(y);
    }

    QPoint getPosition() const {
        return position;
    }

    virtual void draw(QPainter* painter) = 0;

protected:
    QPoint position;
    QColor color;
};

#endif
