//
// Created by LENOVO on 5. 04. 2022.
//

#include "Rectangle.h"
#include <iostream>
#include "PrintUtility.h"
using namespace std;

Rectangle::Rectangle(ColorCode color, int width, int height) {
    this->width=width;
    this->height=height;
    this->color=color;
}

Rectangle::Rectangle() {
}

int Rectangle::getSurfaceArea() {
return width * height;
}

void Rectangle::draw() {
    //Shape2D::draw();
    for(int k=0; k<height;k++) {
        for (int i = 0; i < width; i++) {
            PrintUtility::print(color,1);
        }
        cout<<"\n";
    }
}

std::string Rectangle::toString() const{
    return std::to_string(height) + "\n" + std::to_string(width);
}

/*void Rectangle::setWidth(int width) {
this->width=width;
}

void Rectangle::setHeight(int height) {
this->height= height;
}*/
