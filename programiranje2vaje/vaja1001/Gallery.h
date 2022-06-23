//
// Created by LENOVO on 18. 05. 2022.
//

#ifndef VAJA1001_GALLERY_H
#define VAJA1001_GALLERY_H

#include <string>
#include "Artwork.h"
#include<vector>
#include "Painting.h"
#include<algorithm>
#include"PrintIfPainting.h"


class Gallery {
private:
    std::string name;
    vector<Artwork *> artworks;
public:
    Gallery() = default;

    Gallery(std::string n);

    void addArtwork(Artwork *artwork);

    void removeArtwork(Artwork *artwork);

    void printArtworks() const;

    std::string toString() const;

    vector<Artwork *> getArtworkBetweenYear(unsigned int startYear, unsigned int endYear) const;

    void sort(bool(*c)(Artwork*,Artwork*));

    Artwork* find(bool (*c)(Artwork*));
    void printArtworks(PrintIfPainting i);
    vector<Artwork *> findAll(bool(*c)(Artwork*));
};




#endif //VAJA1001_GALLERY_H
