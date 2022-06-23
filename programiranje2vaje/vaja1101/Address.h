//
// Created by LENOVO on 24. 05. 2022.
//

#ifndef VAJA1101_ADDRESS_H
#define VAJA1101_ADDRESS_H
#include<string>


class Address {
private:
std::string street;
std::string post;
std::string country;
public:
    Address(std::string s, std::string p, std::string c) : street(s), post(p), country(c){
    }
    std::string toString();

};


#endif //VAJA1101_ADDRESS_H
