//
// Created by LENOVO on 18. 05. 2022.
//

#ifndef VAJA1001_PAINTING_H
#define VAJA1001_PAINTING_H

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



#endif //VAJA1001_PAINTING_H
