//
// Created by LENOVO on 29. 05. 2022.
//

#ifndef VAJA1002A_GALLERY_H
#define VAJA1002A_GALLERY_H


#include <string>
#include "Artwork.h"
#include<vector>
#include "Painting.h"
#include<algorithm>
#include"PrintIfPainting.h"


class Gallery {
private:
    std::string name;
    vector<std::shared_ptr<Artwork>> artworks;
public:
    Gallery() = default;

    Gallery(std::string n);

    void addArtwork(std::shared_ptr<Artwork> artwork);

    void removeArtwork(std::shared_ptr<Artwork> artwork);

    void printArtworks() const;

    std::string toString() const;

    vector<std::shared_ptr<Artwork>> getArtworkBetweenYear(unsigned int startYear, unsigned int endYear) const;

    void sort(bool(*c)(std::shared_ptr<Artwork>,std::shared_ptr<Artwork>));

    std::shared_ptr<Artwork> find(std::function<bool(std::shared_ptr<Artwork>)>c);
    void printArtworks(PrintIfPainting i);
    vector<std::shared_ptr<Artwork>> findAll(bool(*c)(std::shared_ptr<Artwork>));
    void filterOut(std::function<bool(std::shared_ptr<Artwork>)> c);
};



#endif //VAJA1002A_GALLERY_H
