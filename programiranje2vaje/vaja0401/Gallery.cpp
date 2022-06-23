//
// Created by LENOVO on 21. 03. 2022.
//

#include "Gallery.h"
#include<vector>
#include <iostream>
#include "Artwork.h"
#include <string>
#include<sstream>
using namespace std;

Gallery::Gallery(std::string name) {
    this->name=name;
}

void Gallery::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

void Gallery::removeArtwork(Artwork* artwork){
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i]->toString() == artwork->toString()){
            artworks.erase(artworks.begin()+i);
        }
    }
}

void Gallery::printArtworks()const{
    for (int i = 0; i < artworks.size(); i++) {
        artworks[i]->print();
    }
}

vector<Artwork*> Gallery::getArtworkBetweenYear(unsigned int startYear, unsigned int endYear) const{
    vector<Artwork*> temp;
    for(int i = 0; i < artworks. size(); i++){
        if(startYear < artworks[i]->getYear()< endYear){
             temp.push_back(artworks[i]);
        }
    }
    return temp;
}


std::string Gallery::toString()const{
    std::string s;
    for(int i =0; i< artworks.size(); i++){
        s= s + artworks[i]->toString();
    }
    return "name: " + name + "\n umetnina: "+ s ;
}