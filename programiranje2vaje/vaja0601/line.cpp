//
// Created by LENOVO on 5. 04. 2022.
//

#include "line.h"
#include <iostream>
#include "PrintUtility.h"
using namespace std;

line::line(ColorCode color, int lenght) {
this->lenght=lenght;
this->color=color;
}

line::line() {
}

int line::getSurfaceArea() {
    return lenght;
}

void line::draw() {
    //Shape2D::draw();
    for(int i=0; i<lenght; i++){
        PrintUtility::print(color,1);
    }
    cout<<"\n";
}

std::string line::toString() const{
    return std::to_string(lenght) +"\n";
}

void line::setLenght(int lenght) {
this->lenght=lenght;
}

