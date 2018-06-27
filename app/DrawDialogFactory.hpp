#pragma once

#include "DrawDialog.hpp"

class MainWindow;
class Shape;
class Circle;
namespace kylink {
class Rectangle;
}

class Line;

class DrawDialogFactory
{
public:
    DrawDialogFactory();
    ~DrawDialogFactory();

    static DrawDialog* CreateShapeDrawDialog(MainWindow *parent, Shape *shape);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Circle *c);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, kylink::Rectangle *r);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Line *l);
};

