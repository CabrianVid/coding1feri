//
// Created by LENOVO on 29. 03. 2022.
//

#ifndef VAJA0501_SCULPTURE_H
#define VAJA0501_SCULPTURE_H


#include "Artwork.h"
#include<iostream>
#include<string>

enum class Material{
    Wood, Stone, Metal, Clay
};

class Sculpture : public Artwork {
private:
int weight;
Material material;

public:
    Sculpture();
    Sculpture(std::string t, std::string d, double p, int y, Artist *a, int w, Material m):Artwork(y, p,t, d, a), weight(w), material(m) {
    }

    std::string toString() const override;
    void print() const override;
    void setMaterial(Material material);
    void setWeight(int weight);
};


#endif //VAJA0501_SCULPTURE_H
