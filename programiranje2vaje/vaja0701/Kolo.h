//
// Created by LENOVO on 18. 04. 2022.
//

#ifndef VAJA0701_KOLO_H
#define VAJA0701_KOLO_H
#include<string>

class Kolo {
private:
    int steviloKoles;
    int velikostKolesa;
public:
    Kolo(int steviloKoles, int velikostKolesa);
    std::string toString()const;
    Kolo();

};


#endif //VAJA0701_KOLO_H
