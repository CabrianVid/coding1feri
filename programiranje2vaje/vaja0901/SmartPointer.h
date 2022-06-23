//
// Created by LENOVO on 8. 05. 2022.
//

#ifndef VAJA0901_SMARTPOINTER_H
#define VAJA0901_SMARTPOINTER_H

template<typename T>
class SmartPointer{
private:
    T *poljubenObjekt;
public:
    SmartPointer();
    explicit SmartPointer(T *o);
    ~SmartPointer();
    T &operator*();
    T &operator->();

};

template<typename T>
SmartPointer<T>::SmartPointer() {

}

template<typename T>
SmartPointer<T>::~SmartPointer() {
    delete poljubenObjekt;
}

template<typename T>
SmartPointer<T>::SmartPointer(T *o) : poljubenObjekt(o){
}

template<typename T>
T &SmartPointer<T>::operator*() {
    return *poljubenObjekt;
}

template<typename T>
T &SmartPointer<T>::operator->() {
    return poljubenObjekt;
}

#endif //VAJA0901_SMARTPOINTER_H
