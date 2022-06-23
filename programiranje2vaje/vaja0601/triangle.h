//
// Created by LENOVO on 12. 04. 2022.
//

#ifndef VAJA0601A_TRIANGLE_H
#define VAJA0601A_TRIANGLE_H

#include<iostream>
#include <string>
#include "Shape2D.h"

class Triangle : public Shape2D{
protected:
    int width;
    int height;
public:
    Triangle();
    Triangle( ColorCode color, int width, int height);
    int getSurfaceArea() override;
    void draw() override;
    std::string toString() const;
};


#endif //VAJA0601A_TRIANGLE_H
