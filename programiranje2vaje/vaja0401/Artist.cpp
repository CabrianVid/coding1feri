//
// Created by LENOVO on 21. 03. 2022.
//

#include "Artist.h"

#include <utility>
#include "Date.h"

std::string Artist::toString() const{
    return name+ "\n" + biography
           + "\n" + dateOfBirth.toString();
}

Artist::Artist(std::string name, std::string biography, Date dateOfBirth) : dateOfBirth(dateOfBirth) {
    this->name = std::move(name);
    this->biography = std::move(biography);
}