//
// Created by LENOVO on 2. 05. 2022.
//

#ifndef VAJA0801A_LINE_H
#define VAJA0801A_LINE_H

#include <string>

class Line{
private:
    int izhodisce;
    int konec;
public:
    Line(int izhodisce, int konec);
    std::string toString();

};

Line::Line(int izhodisce, int konec) {
this->izhodisce=izhodisce;
this->konec=konec;
}

std::string Line::toString() {
    return std::to_string(izhodisce) + std::to_string(konec);
}


#endif //VAJA0801A_LINE_H
