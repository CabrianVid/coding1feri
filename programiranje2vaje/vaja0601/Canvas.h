//
// Created by LENOVO on 5. 04. 2022.
//

#ifndef VAJA0601A_CANVAS_H
#define VAJA0601A_CANVAS_H


#include "Shape2D.h"
#include<vector>

class Canvas {
private:
    std::vector<Shape2D*> shapes;

public:
    void addShape(Shape2D* shape2d);
    void print() const;





};



#endif //VAJA0601A_CANVAS_H
