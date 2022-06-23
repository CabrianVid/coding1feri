//
// Created by LENOVO on 20. 03. 2022.
//

#ifndef VAJA0401_ARTWORK_H
#define VAJA0401_ARTWORK_H


#include <string>
#include "Artist.h"


using namespace std;


class Artwork {
private:
    std::string title;
    std::string description;
    double price;
    int year;
    Artist *artist;
public:
    //constructors
    Artwork();
    Artwork(int year, double price, std::string title, std::string description, Artist* artist);

    //methods
    int getYear() const;

    void setYear(int year);

    double getPrice() const;

    void setPrice(double price);

    std::string getTitle();

    void setTitle(std::string title);

    std::string getDescription();

    void setDescription(std::string description);

    std::string toString() const;

    void print() const;

    bool isExpensier(const Artwork *drugi) const;

    void setArtist(Artist* artist);

};
#endif //VAJA0401_ARTWORK_H
