//
// Created by LENOVO on 18. 05. 2022.
//


#include "Sculpture.h"
#include"Artwork.h"
#include<iostream>


Sculpture::Sculpture(std::string title, std::string description, double price, int year, Artist *artist, int weight,
                     Material material) {
    this->title = std::move(title);
    this->price = price;
    this->description = std::move(description);
    this->year = year;
    this->artist = artist;
    this->weight = weight;
    this->material = material;
}

std::string Sculpture::toString() const {
    std::string str = Artwork::toString() + std::to_string(weight);

    switch (material) {
        case Material::Wood:
            return str + "\nWood";
        case Material::Stone:
            return str + "\nStone";
        case Material::Metal:
            return str + "\nMetal";
        case Material::Clay:
            return str + "\nClay";
        default:
            return str + "\nempty";
    }
}

void Sculpture::print() const {
    std::cout << toString() << "\n";
}


Sculpture::Sculpture() {
}

void Sculpture::setMaterial(Material material) {
    this->material = material;

}

void Sculpture::setWeight(int weight) {
    this->weight = weight;

}
