//
// Created by LENOVO on 29. 05. 2022.
//

#ifndef VAJA1002A_PRINTIFPAINTING_H
#define VAJA1002A_PRINTIFPAINTING_H

#include "Artwork.h"

class PrintIfPainting {
public:
    void operator()(std::shared_ptr<Artwork> e);
};



#endif //VAJA1002A_PRINTIFPAINTING_H
