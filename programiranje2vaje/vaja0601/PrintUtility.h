//
// Created by LENOVO on 5. 04. 2022.
//

#ifndef VAJA0601A_PRINTUTILITY_H
#define VAJA0601A_PRINTUTILITY_H


#include "ColorCode.h"


class PrintUtility {
private:
    PrintUtility() = default;
public:
    static void print(const ColorCode &color, const std::string& str);
    static void print(const ColorCode &color, unsigned int n);
};

#endif //VAJA0601A_PRINTUTILITY_H
