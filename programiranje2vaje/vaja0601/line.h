//
// Created by LENOVO on 5. 04. 2022.
//

#ifndef VAJA0601A_LINE_H
#define VAJA0601A_LINE_H


#include "ColorCode.h"
#include <string>
#include "Shape2D.h"

class line: public Shape2D{
protected:
    int lenght;
public:
    line();
    line(ColorCode color, int lenght);
    int getSurfaceArea() override;
    void draw() override;
    std::string toString() const;
    void setLenght(int lenght);
};


#endif //VAJA0601A_LINE_H
