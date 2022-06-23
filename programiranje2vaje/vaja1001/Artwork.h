//
// Created by LENOVO on 18. 05. 2022.
//

#ifndef VAJA1001_ARTWORK_H
#define VAJA1001_ARTWORK_H



#include <string>
#include "Artist.h"


using namespace std;


class Artwork {
protected:
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

    virtual std::string toString() const;

    virtual void print() const;

    bool isExpensier(const Artwork *drugi) const;

    void setArtist(Artist* artist);

};


#endif //VAJA1001_ARTWORK_H
