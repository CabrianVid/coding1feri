//
// Created by LENOVO on 29. 03. 2022.
//

#include "Sculpture.h"
#include"Artwork.h"



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
    cout << toString() << "\n";
}


Sculpture::Sculpture() {
}

void Sculpture::setMaterial(Material material) {
    this->material = material;

}

void Sculpture::setWeight(int weight) {
    this->weight = weight;

}
