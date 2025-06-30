#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <vector>
#include "point.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    std::vector<Point*> figures;
    QPoint lastMousePos;

    Point* createRandomFigure(int x, int y);

    void setCircle();
    void setSquare();
    void setTriangle();
};

#endif
