//
// Created by LENOVO on 28. 03. 2022.
//

#ifndef VAJA0501_ARTIST_H
#define VAJA0501_ARTIST_H

#include <string>
#include "Date.h"


class Artist {
private:
    std::string name;
    std::string biography;
    Date dateOfBirth;
public:
    Artist(std::string name, std::string biography, Date dateOfBirth);

    std::string toString() const;


};


#endif //VAJA0501_ARTIST_H
