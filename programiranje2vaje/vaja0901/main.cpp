#include <iostream>
#include<memory>
#include "Date.h"
#include "SmartPointer.h"
#include "Praznik.h"

int main() {
    SmartPointer<Date> datum1(new Date (4,7,2000));
    SmartPointer<Date> datum2(new Date (4,6,2000));

    bool sameDate= *datum1 == *datum2;
    std::cout << sameDate;
    std::cout<<"\n";

    std::shared_ptr<Date>sP(new Date(6,9,2010));
    std::cout<< *sP;

    std::cout<<"\n";


    SmartPointer<Praznik> praznik1(new Praznik(2,9));
    auto praznik2= std::make_shared <Praznik>(6,9);
    std::cout<< *praznik2;
    std::cout<<"\n";
    std::cout<<"gggggg0"<< --(*praznik2);
    std::cout<<"\n";
    std::cout<<"gggggg" <<(*praznik2)--;
    std::cout<<"2222222\n";
    std::cout<< *praznik2;
    return 0;
}
