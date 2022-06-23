//
// Created by LENOVO on 24. 05. 2022.
//

#ifndef VAJA1101_STUDENT_H
#define VAJA1101_STUDENT_H


#include <string>
#include "Date.h"
#include "Address.h"
#include "WrongPhoneNumberException.h"
#include<vector>
#include <memory>

class Student {
private:
unsigned int id;
std::string name;
std::string surname;
Date dateOfBirth;
Address address;
std::string phone;
public:
    Student(unsigned int i, std::string n, std::string s, Date d, Address a, std::string p): id(i), name(n), surname(s), dateOfBirth(d), address(a){
        bool allDigits= true;
        for (char const &c : p) {
            if (std::isdigit(c)==0){
                allDigits= false;
            }
        }
        if(allDigits){
            this->phone=p;
        }
        else{
            throw WrongPhoneNumberException(p);
        }
    }
    std::string toString();
    static std::vector<std::shared_ptr<Student>> LoadFromFile(const std::string &filename);
    static void SaveToFile(const std::vector<std::shared_ptr<Student>> &students, const std::string &fileName);

};


#endif //VAJA1101_STUDENT_H
