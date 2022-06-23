//
// Created by LENOVO on 24. 05. 2022.
//

#include "Address.h"

std::string Address::toString() {
    std::string temp= street + ","+post+","+ country;
    return temp;
}
