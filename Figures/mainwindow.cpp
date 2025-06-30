#include "mainwindow.h"
#include <QMenuBar>
#include <QPainter>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(600, 600);
    setMouseTracking(true);
    srand(time(nullptr));

    QMenu* menu = menuBar()->addMenu("Figures");
    QAction* actCircle = menu->addAction("Circle");
    QAction* actSquare = menu->addAction("Square");
    QAction* actTriangle = menu->addAction("Triangle");

    connect(actCircle, &QAction::triggered, this, &MainWindow::setCircle);
    connect(actSquare, &QAction::triggered, this, &MainWindow::setSquare);
    connect(actTriangle, &QAction::triggered, this, &MainWindow::setTriangle);

    lastMousePos = QPoint(width() / 2, height() / 2);
}

MainWindow::~MainWindow() {
    for (Point* fig : figures)
        delete fig;
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    for (Point* fig : figures) {
        fig->draw(&painter);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    QPoint currentPos = event->pos();

    if ((currentPos - lastMousePos).manhattanLength() < 10)
        return;

    for (int i = figures.size() - 1; i > 0; --i) {
        figures[i]->setPosition(
            figures[i - 1]->getPosition().x(),
            figures[i - 1]->getPosition().y()
            );
    }

    if (!figures.empty()) {
        figures[0]->setPosition(currentPos.x(), currentPos.y());
    }

    Point* newFig = createRandomFigure(lastMousePos.x(), lastMousePos.y());
    figures.push_back(newFig);

    if (figures.size() > 20) {
        delete figures.front();
        figures.erase(figures.begin());
    }

    lastMousePos = currentPos;

    update();
}

Point* MainWindow::createRandomFigure(int x, int y) {
    int t = rand() % 3;
    QColor c(rand() % 256, rand() % 256, rand() % 256);

    switch (t) {
    case 0: return new Circle(x, y, c);
    case 1: return new Square(x, y, c);
    case 2: return new Triangle(x, y, c);
    }

    return new Circle(x, y, c);
}

void MainWindow::setCircle() {
    Point* p = new Circle(width() / 2, height() / 2);
    figures.push_back(p);

    if (figures.size() > 20) {
        delete figures.front();
        figures.erase(figures.begin());
    }

    update();
}

void MainWindow::setSquare() {
    Point* p = new Square(width() / 2, height() / 2);
    figures.push_back(p);

    if (figures.size() > 20) {
        delete figures.front();
        figures.erase(figures.begin());
    }

    update();
}

void MainWindow::setTriangle() {
    Point* p = new Triangle(width() / 2, height() / 2);
    figures.push_back(p);

    if (figures.size() > 20) {
        delete figures.front();
        figures.erase(figures.begin());
    }

    update();
}
