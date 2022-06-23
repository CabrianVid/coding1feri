//
// Created by LENOVO on 18. 05. 2022.
//

#include "Gallery.h"
#include<vector>
#include <iostream>
#include "Artwork.h"
#include <string>
#include<sstream>


using namespace std;

Gallery::Gallery(std::string n) : name(n) {

}

void Gallery::addArtwork(Artwork *artwork) {
    artworks.push_back(artwork);
}


void Gallery::removeArtwork(Artwork *artwork) {
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i]->toString() == artwork->toString()) {
            artworks.erase(artworks.begin() + i);
        }
    }
}

void Gallery::printArtworks() const {
    for (int i = 0; i < artworks.size(); i++) {
        artworks[i]->print();
    }
}

vector<Artwork *> Gallery::getArtworkBetweenYear(unsigned int startYear, unsigned int endYear) const {
    vector<Artwork *> temp;
    for (int i = 0; i < artworks.size(); i++) {
        if (startYear < artworks[i]->getYear() < endYear) {
            temp.push_back(artworks[i]);
        }
    }
    return temp;
}


std::string Gallery::toString() const {
    std::string s;
    for (int i = 0; i < artworks.size(); i++) {
        s = s + artworks[i]->toString();
    }
    return "name: " + name + "\n umetnina: " + s;
}



void Gallery::sort(bool (*c)(Artwork *, Artwork *)) {
    Artwork *temp;
    for (int j = 0; j < artworks.size() - 1; j++) {
        for (int i = 0; i < artworks.size() - j - 1; i++) {
            if (!c(artworks[i], artworks[i + 1])) {
                temp = artworks[i];
                artworks[i] = artworks[i + 1];
                artworks[i + 1] = temp;
            }
        }
    }

}

Artwork *Gallery::find(bool (*c)(Artwork *)) {
   auto it = std::find_if (artworks.begin(), artworks.end(), c);
if(it!=artworks.end() && c(*it)){//tu ono
    return *it;
}
   else{
       return new Artwork();
   }


}

void Gallery::printArtworks(PrintIfPainting i) {
    std::for_each(artworks.begin(), artworks.end(), i);
}

vector<Artwork *> Gallery::findAll(bool (*c)(Artwork *)) {

    vector<Artwork *>temp;
    for(auto x : artworks){
        if(c(x)){
            temp.push_back(x);
        }
    }
    return temp;
}
