//
// Created by LENOVO on 29. 05. 2022.
//



#include "Painting.h"
#include <utility>
#include <iostream>

using namespace std;

Painting::Painting(std::string title, std::string description, double price, int year, std::shared_ptr<Artist> artist,
                   paintingTechnique technique) {
    this->title = std::move(title);
    this->price = price;
    this->description = std::move(description);
    this->year = year;
    this->artist = artist;
    this->technique = technique;
}

std::string Painting::toString() const {
    std::string str= Artwork::toString();
    switch (technique) {
        case paintingTechnique::Oil:
            return str + "\nOil";
        case paintingTechnique::Acrylic:
            return str + "\nAcrylic";
        case paintingTechnique::Graphite:
            return str + "\nGraphite";
        default:
            return str + "\nempty";
    }
}

void Painting::print() const {

    cout << toString() << "\n";
}

void Painting::setTechnique(paintingTechnique technique) {
    this->technique = technique;
}

Painting::Painting() {
}

