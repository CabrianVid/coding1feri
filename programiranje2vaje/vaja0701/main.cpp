#include <iostream>
#include"Avto.h"
#include"Kolo.h"
#include<vector>
#include <ctime>
#include"VectorUtil.h"



int main() {
    std::srand(std::time(NULL));

    std::vector<Avto> avtomobili;
    fillDefault<8>(avtomobili);
    print(avtomobili);

    std::vector<Avto> avtomobili2;
    avtomobili2=reverse(avtomobili);
    print(avtomobili2);

    std::vector<Kolo> kolesa;
    fillDefault<9>(kolesa);
    print(kolesa);
    std::vector<Kolo> kolesa1;
    fillDefault<9>(kolesa1);

    std::vector<std::vector<Kolo>> veckoles;
    veckoles.push_back(kolesa);
    veckoles.push_back(kolesa1);

    mergeList(veckoles);
    std::vector<std::vector<std::string>> stringkoles;
    stringkoles.push_back(std::vector<std::string> {"fufhsu", "dfsfssdfsd"});
    stringkoles.push_back(std::vector<std::string> {"fdsfs", "wrt"});
    std::cout << mergeList(stringkoles);

    return 0;
}
