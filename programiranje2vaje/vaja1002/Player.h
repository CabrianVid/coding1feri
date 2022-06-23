//
// Created by LENOVO on 31. 05. 2022.
//

#ifndef VAJA1002A_PLAYER_H
#define VAJA1002A_PLAYER_H
#include <iostream>
#include<string>

class Player {
protected:
    std::string name;
    std::string club;
    int number;
public:
    Player(std::string n,std::string c,int nu) :name(n), club(c), number(nu){
    }
    virtual ~Player() {
    }
    virtual void print() const {
        std::cout << "Player: " << name << " " << club << " " << number << std::endl;
    }
};


#endif //VAJA1002A_PLAYER_H
