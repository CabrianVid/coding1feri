//
// Created by LENOVO on 29. 05. 2022.
//

#ifndef VAJA1002A_ARTIST_H
#define VAJA1002A_ARTIST_H


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
#endif //VAJA1002A_ARTIST_H
