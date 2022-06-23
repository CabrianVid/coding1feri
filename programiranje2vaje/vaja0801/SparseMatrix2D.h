//
// Created by LENOVO on 2. 05. 2022.
//

#ifndef VAJA0801A_SPARSEMATRIX2D_H
#define VAJA0801A_SPARSEMATRIX2D_H


#include<vector>
#include<iostream>
#include"Element.h"
#include<algorithm>

using namespace std;


template<typename T>
class SparseMatrix2D {
private:
    std::vector<Element<T>> elements;
    unsigned int sizeX;
    unsigned int sizeY;
    T defaultElement;
public:
    SparseMatrix2D(unsigned int sizeX, unsigned int sizeY, T defaultElement);

    void set(unsigned int x, unsigned int y, T value);

    T at(unsigned int x, unsigned int y);

    unsigned int getSizeX();

    unsigned int getSizeY();


    void clearRow( unsigned int rowX);
    void clearColum( unsigned int rowY);
    void setSizeY(unsigned int a);


};

template<typename T>
SparseMatrix2D<T>::SparseMatrix2D(unsigned int sizeX, unsigned int sizeY, T defaultElement) :
        sizeX(sizeX), sizeY(sizeY), defaultElement(defaultElement) {
            /*for(int j=0;j<sizeY;j++){
                for(int i=0;i<sizeX;i++){
                    elements.push_back(Element<T>(i, j, defaultElement));
                }
            }*/

        }


template<typename T>
void SparseMatrix2D<T>::set(unsigned int x, unsigned int y, T value) {
    if (x < sizeX && y < sizeY) {
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i].getX() == x && elements[i].getY() == y) {
                elements[i].setValue(value);
                return;
            }
        }
        elements.push_back(Element<T>(x, y, value));
    }
}

template<typename T>
T SparseMatrix2D<T>::at(unsigned int x, unsigned int y) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].getX() == x && elements[i].getY() == y) {
            return elements[i].getValue();
        }
    }
    return  defaultElement;
}

template<typename T>
unsigned int SparseMatrix2D<T>::getSizeX() {
    return sizeX;
}

template<typename T>
unsigned int SparseMatrix2D<T>::getSizeY() {
    return sizeY;
}


template<typename T>
void SparseMatrix2D<T>::clearRow(unsigned int rowX) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].getX() == rowX) {
            elements.erase(elements.begin() + i);
            i--;
        }

    }


}

template<typename T>
void SparseMatrix2D<T>::clearColum(unsigned int rowY) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].getY() == rowY) {
            elements.erase(elements.begin() + i);
            i--;
            continue;
        }
        if(elements[i].getY()>rowY){
            elements[i].setY(elements[i].getY()-1);
        }
    }
    setSizeY(sizeY-1);

}

template<typename T>
void SparseMatrix2D<T>::setSizeY(unsigned int a) {
    this->sizeY=a;

}




/*
template<typename T>
void SparseMatrix2D<T>::clearRow(unsigned int rowX) {
    std::vector<Element<T>> temp;
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].getX() != rowX) {
            temp.push_back(elements[i]);
        }
    }
    elements.clear();
    for (int i = 0; i < temp.size(); i++) {
        elements.push_back(temp[i]);
    }
}
*/



#endif //VAJA0801A_SPARSEMATRIX2D_H
