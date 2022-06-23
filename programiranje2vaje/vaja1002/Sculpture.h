//
// Created by LENOVO on 29. 05. 2022.
//

#ifndef VAJA1002A_SCULPTURE_H
#define VAJA1002A_SCULPTURE_H


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
    Sculpture(std::string title, std::string description, double price, int year, std::shared_ptr<Artist>artist,int weight, Material material);
    std::string toString() const override;
    void print() const override;
    void setMaterial(Material material);
    void setWeight(int weight);
};


#endif //VAJA1002A_SCULPTURE_H
