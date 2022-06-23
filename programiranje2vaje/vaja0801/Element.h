//
// Created by LENOVO on 2. 05. 2022.
//

#ifndef VAJA0801A_ELEMENT_H
#define VAJA0801A_ELEMENT_H



#include <vector>

template <typename T>
class Element{
private:
    unsigned int x;
    unsigned int y;
    T value;

public:
    Element();
    Element(unsigned int x, unsigned int y, T value);
    void setX(unsigned int x);
    void setY(unsigned int y);
    void setValue(T value);
    unsigned int getX();
    unsigned int getY();
    T getValue();

};

template<typename T>
Element<T>::Element(unsigned int x, unsigned int y, T value) : x(x), y(y), value(value){

}

template<typename T>
void Element<T>::setX(unsigned int x) {
    this->x=x;
}

template<typename T>
void Element<T>::setY(unsigned int y) {
    this->y=y;
}

template<typename T>
void Element<T>::setValue(T value) {
    this->value=value;
}

template<typename T>
T Element<T>::getValue() {
    return value;

}

template<typename T>
unsigned int Element<T>::getX() {
    return x;
}

template<typename T>
unsigned int Element<T>::getY() {
    return y;
}

template<typename T>
Element<T>::Element() {

}



#endif //VAJA0801A_ELEMENT_H
