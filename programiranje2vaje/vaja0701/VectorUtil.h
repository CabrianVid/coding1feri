//
// Created by LENOVO on 18. 04. 2022.
//

#ifndef VAJA0701_VECTORUTIL_H
#define VAJA0701_VECTORUTIL_H

#endif //VAJA0701_VECTORUTIL_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

template<int N, typename T>
void fillDefault(std::vector<T> &vec) {
    std::cout << "Default\n";
    for (int i = 0; i < N; ++i) {
        vec.push_back(T());
    }
}

template<typename T>
std::string toString(std::vector<T> vec) {
    std::string temp;
    for (int i = 0; i < vec.size(); ++i) {
        temp += vec[i].toString();
    }
    return temp;
}

template<typename T>
void print(std::vector<T> vec) {
    std::cout << toString(vec) << "\n";
}

template<typename T>
std::vector<T> reverse(std::vector<T> vec) {

    std::vector<T> temp1(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        temp1[i] = vec[vec.size() - i - 1];
    }

    return temp1;
}

int randomNumber() {
    int random_variable = (std::rand() % 10) + 1;
    return random_variable;

}

template<int N>
void fillDefault(std::vector<Kolo> &vec) {
    std::cout << "Special\n";
    for (int i = 0; i < N; ++i) {
        vec.push_back(Kolo(randomNumber(), randomNumber()));
    }
}

template<typename T>
std::vector<T> mergeList(std::vector<std::vector<T>> &vec) {
    std::vector<T> temp1;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            temp1.push_back(vec[i][j]);
        }
    }
    return temp1;
}


std::string mergeList(std::vector<std::vector<std::string>> &vec) {
    std::string temp;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            temp += vec[i][j];
        }
    }
    return temp;
}


