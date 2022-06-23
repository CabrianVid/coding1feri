//
// Created by LENOVO on 29. 05. 2022.
//

#ifndef VAJA1002A_PAINTING_H
#define VAJA1002A_PAINTING_H


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

    Painting(std::string title, std::string description, double price, int year, std::shared_ptr<Artist> artist,
             paintingTechnique technique);

    std::string toString() const override;

    void print() const override;

    void setTechnique(paintingTechnique technique);
};


#endif //VAJA1002A_PAINTING_H
