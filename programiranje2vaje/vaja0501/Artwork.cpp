//
// Created by LENOVO on 28. 03. 2022.
//

#include "Artwork.h"
#include <iostream>
#include <sstream>

using namespace std;

int Artwork::getYear() const {
    return year;
}

double Artwork::getPrice() const {
    return price;
}

std::string Artwork::getTitle() {
    return title;
}

std::string Artwork::getDescription() {
    return description;
}

void Artwork::setYear(int year) {
    this->year = year;
}

void Artwork::setPrice(double price) {
    this->price = price;
}

void Artwork::setTitle(std::string title) {
    this->title = title;
}

void Artwork::setDescription(std::string description) {
    this->description = description;
}

void Artwork::print() const {
    cout << title << "\t" << year << "\n";
    cout << price << "\n" << description << "\n";
}

std::string Artwork::toString() const {
    return "title: " + title + "\n year: " + std::to_string(year)
           + "\n price: " + std::to_string(price) + "$\n" + description;
}

Artwork::Artwork() : year(0), price(0), title(), description(), artist() {

}

Artwork::Artwork(int year, double price, std::string title, std::string description, Artist *artist) {
    this->year = year;
    this->price = price;
    this->title = title;
    this->description = description;
    this->artist = artist;
}


bool Artwork::isExpensier(const Artwork *drugi) const {
    if (this->getPrice() < drugi->getPrice()) {
        return true;
    } else {
        return false;
    }
}

void Artwork::setArtist(Artist *artist) {
    this->artist = artist;
}