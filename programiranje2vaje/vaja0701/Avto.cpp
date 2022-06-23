//
// Created by LENOVO on 18. 04. 2022.
//

#include "Avto.h"

Avto::Avto(int steviloKolesAvta, int stevilkaAvta) {
this->steviloKolesAvta=steviloKolesAvta;
this->stevilkaAvta=stevilkaAvta;
}

std::string Avto::toString() const {
    return std::to_string(steviloKolesAvta)+ std::to_string(stevilkaAvta);
}

Avto::Avto() {
}
