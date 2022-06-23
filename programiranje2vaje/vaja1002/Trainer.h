//
// Created by LENOVO on 31. 05. 2022.
//

#ifndef VAJA1002A_TRAINER_H
#define VAJA1002A_TRAINER_H
#include <iostream>
#include<string>

class Trainer {
protected:
    std::string name;
    std::string club;
    int yearsOfExperiance;
public:
    Trainer(std::string n,std::string c,int y): name(n), club(c), yearsOfExperiance(y){
    }
    virtual ~Trainer(){};
    virtual void print() const {
        std::cout << "Trainer: " << name << " " << club << " " << yearsOfExperiance << std::endl;
    }

};


#endif //VAJA1002A_TRAINER_H
