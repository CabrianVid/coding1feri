//
// Created by LENOVO on 28. 03. 2022.
//

#ifndef VAJA0501_GALLERY_H
#define VAJA0501_GALLERY_H

#include <string>
#include "Artwork.h"
#include<vector>
#include "Painting.h"

class Gallery {
private:
    std::string name;
    vector<Artwork *> artworks;
public:
    Gallery() = default;

    Gallery(std::string name);

    void addArtwork(Artwork *artwork);

    void removeArtwork(Artwork *artwork);

    void printArtworks() const;

    std::string toString() const;

    vector<Artwork *> getArtworkBetweenYear(unsigned int startYear, unsigned int endYear) const;
};


#endif //VAJA0501_GALLERY_H
