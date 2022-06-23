//
// Created by LENOVO on 18. 04. 2022.
//

#ifndef VAJA0701_AVTO_H
#define VAJA0701_AVTO_H

#include<iostream>
#include<string>
class Avto {

    private:
        int steviloKolesAvta;
        int stevilkaAvta;
    public:
        Avto(int steviloKolesAvta, int stevilkaAvta);
        Avto();
        std::string toString()const;



};


#endif //VAJA0701_AVTO_H
