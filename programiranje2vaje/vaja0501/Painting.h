//
// Created by LENOVO on 28. 03. 2022.
//

#ifndef VAJA0501_PAINTING_H
#define VAJA0501_PAINTING_H

#include "Artwork.h"
#include "Artist.h"
#include<string>

enum class paintingTechnique {
    Oil, Acrylic, Graphite
};

class Painting : public Artwork {
private:
    paintingTechnique technique;

public:
    Painting();

    Painting(std::string title, std::string description, double price, int year, Artist *artist,
             paintingTechnique technique);

    std::string toString() const override;

    void print() const override;

    void setTechnique(paintingTechnique technique);
};


#endif //VAJA0501_PAINTING_H
