//
// Created by LENOVO on 18. 05. 2022.
//

#ifndef VAJA1001_SCULPTURE_H
#define VAJA1001_SCULPTURE_H


#include "Artwork.h"

enum class Material{
    Wood, Stone, Metal, Clay
};

class Sculpture : public Artwork {
private:
    int weight;
    Material material;

public:
    Sculpture();
    Sculpture(std::string title, std::string description, double price, int year, Artist *artist,int weight, Material material);
    std::string toString() const override;
    void print() const override;
    void setMaterial(Material material);
    void setWeight(int weight);
};


#endif //VAJA1001_SCULPTURE_H
