//
// Created by LENOVO on 5. 04. 2022.
//

#include "Canvas.h"
#include <iostream>
using namespace std;

void Canvas::addShape(Shape2D *shade2d) {
shapes.push_back(shade2d);
}



void Canvas::print() const {
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
        cout<<"\n";
    }
}

