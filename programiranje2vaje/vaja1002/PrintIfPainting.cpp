//
// Created by LENOVO on 29. 05. 2022.
//

#include<iostream>
#include "PrintIfPainting.h"
#include"Painting.h"

void PrintIfPainting::operator()(std::shared_ptr<Artwork>e) {
    if(dynamic_pointer_cast<std::shared_ptr<Painting>>(e))
        std::cout << e->toString()<<std::endl;
}
