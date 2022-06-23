//
// Created by LENOVO on 6. 03. 2022.
//

#ifndef VAJA0201_ARTWORK_H
#define VAJA0201_ARTWORK_H


#include <string>


using namespace std;


class Artwork {
private:
    std::string title;
    std::string description;
    double price;
    int year;
public:
    //constructors
    Artwork();

    ~Artwork();

    Artwork(const Artwork &t);

    Artwork(int year, double price, std::string title, std::string description);

    //methods
    int getYear();

    void setYear(int year);

    double getPrice() const;

    void setPrice(double price);

    std::string getTitle();

    void setTitle(std::string title);

    std::string getDescription();

    void setDescription(std::string description);

    std::string toString() const;

    void print() const;

    bool isExpensier(const Artwork* drugi) const;
    /*{
        if(this->getPrice() < drugi->getPrice()){
            return true;
        }
        else {
            return false;
        }
    }*/


};


#endif //VAJA0201_ARTWORK_H
