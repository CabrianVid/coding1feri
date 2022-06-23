//
// Created by LENOVO on 5. 04. 2022.
//

#ifndef VAJA0601A_SHAPE2D_H
#define VAJA0601A_SHAPE2D_H

#include "ColorCode.h"


class Shape2D {
protected:

    ColorCode color;

public:

    Shape2D(ColorCode color);

    Shape2D();

    virtual int getSurfaceArea() = 0;

    virtual void draw() = 0;

};


#endif //VAJA0601A_SHAPE2D_H
