//
// Created by LENOVO on 12. 04. 2022.
//

#include "triangle.h"
#include"Shape2D.h"
#include"PrintUtility.h"
using namespace std;


Triangle::Triangle(ColorCode color, int width, int height) {
    this->color=color;
    this->width=width;
    this->height=height;
}

Triangle::Triangle() {
}

int Triangle::getSurfaceArea() {
    return (height*width)/2;
}

void Triangle::draw() {

    for (int i=1; i<=height;i++)
    {
        for (int j=1; j<=2*i-1;j++)
            PrintUtility::print(color,1);
        cout<<endl;
    }

}

std::string Triangle::toString() const{
    return std::to_string(height) + "\n" + std::to_string(width);
}
