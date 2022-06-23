//
// Created by LENOVO on 21. 03. 2022.
//

#ifndef VAJA0401_ARTIST_H
#define VAJA0401_ARTIST_H


#include <string>
#include "Date.h"


class Artist {
private:
    std::string name;
    std::string biography;
    Date dateOfBirth;
public:
    Artist(std::string name,std::string biography,Date dateOfBirth);
    std::string toString() const;


};


#endif //VAJA0401_ARTIST_H
