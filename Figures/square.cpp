#include "square.h"

Square::Square(int x, int y, QColor color) : Point(x, y, color) {}

void Square::draw(QPainter* painter) {
    painter->setBrush(color);
    painter->drawRect(position.x() - 40, position.y() - 40, 80, 80);
}
