//
// Created by LENOVO on 5. 04. 2022.
//

#ifndef VAJA0601A_RECTANGLE_H
#define VAJA0601A_RECTANGLE_H

#include <string>
#include "Shape2D.h"

class Rectangle:public Shape2D {
protected:
    int width;
    int height;
public:
    Rectangle();
    Rectangle( ColorCode color, int width, int height);
    int getSurfaceArea() override;
    void draw() override;
    std::string toString() const;
    //void setWidth(int width);
    //void setHeight(int height);


};



#endif //VAJA0601A_RECTANGLE_H
