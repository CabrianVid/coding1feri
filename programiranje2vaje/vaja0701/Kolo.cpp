//
// Created by LENOVO on 18. 04. 2022.
//

#include "Kolo.h"

Kolo::Kolo(int steviloKoles, int velikostKolesa) {
this->steviloKoles=steviloKoles;
this->velikostKolesa=velikostKolesa;
}

std::string Kolo::toString() const {
    return std::to_string(steviloKoles )+ std::to_string(velikostKolesa);
}

Kolo::Kolo() {
}
