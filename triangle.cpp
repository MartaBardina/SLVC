#include "triangle.h"

Triangle::Triangle(int x, int y, QColor color) : Point(x, y, color) {}

void Triangle::draw(QPainter* painter) {
    painter->setBrush(color);
    QPointF points[3] = {
        QPointF(position.x(), position.y() - 40),
        QPointF(position.x() - 40, position.y() + 40),
        QPointF(position.x() + 40, position.y() + 40)
    };
    painter->drawPolygon(points, 3);
}
