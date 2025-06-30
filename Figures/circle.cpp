#include "circle.h"

Circle::Circle(int x, int y, QColor color) : Point(x, y, color) {}

void Circle::draw(QPainter* painter) {
    painter->setBrush(color);
    painter->drawEllipse(position, 80, 80);
}
