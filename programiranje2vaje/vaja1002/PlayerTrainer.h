//
// Created by LENOVO on 31. 05. 2022.
//

#ifndef VAJA1002A_PLAYERTRAINER_H
#define VAJA1002A_PLAYERTRAINER_H
#include<iostream>
#include "Player.h"
#include "Trainer.h"

class PlayerTrainer: public Player, public Trainer{
public:
    PlayerTrainer (std::string n, std::string c, int nu, int ye):
        Player(n, c, nu), Trainer(n, c, ye){

    }

    void print() const{
        std::cout<< "Player-Trainer:"<< Player::name<< " "<< Player::club<<" "<<Player::number<< Trainer::yearsOfExperiance;
    }
};


#endif //VAJA1002A_PLAYERTRAINER_H
