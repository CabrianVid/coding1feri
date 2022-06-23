#include <iostream>
#include"PrintUtility.h"
#include "Shape2D.h"
#include "Canvas.h"
#include "Rectangle.h"
#include "line.h"
#include "triangle.h"
#include<string>


int main() {
    system(("chcp " + std::to_string(65001)).c_str());

    Canvas canvas;
    canvas.addShape(new Rectangle(ColorCode(ColorCode::green), 5, 2));
    canvas.addShape(new Rectangle(ColorCode(ColorCode::blue), 10, 5));
    canvas.addShape(new line(ColorCode(ColorCode::green), 5));
    canvas.addShape(new line(ColorCode(ColorCode::blue), 10));
    canvas.addShape(new Triangle(ColorCode(ColorCode::blue), 10, 10));
    canvas.print();










    return 0;
}
