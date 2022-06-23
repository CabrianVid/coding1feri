//
// Created by LENOVO on 24. 05. 2022.
//

#include "Student.h"
#include"UnparseableDateException.h"
#include<string>
#include <fstream>
#include <sstream>

std::string Student::toString() {
    std::string temp = name + "," + surname + "," + dateOfBirth.toString() + "," + address.toString() + ","+ phone;
    return temp;
}



std::vector<std::shared_ptr<Student>> Student::LoadFromFile(const std::string &filename) {
    std::vector<std::shared_ptr<Student>> students;
    Date date1;
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cout << "ERROR";
        return {};
    } else {
        while (!f.eof()) {
            std::vector<std::string> vrstica;
            std::string temp;
            std::getline(f, temp);
            std::istringstream onlyStudent(temp);
            while (onlyStudent.good()) {
                std::string temp2;
                getline(onlyStudent, temp2, ',');
                vrstica.push_back(temp2);
            }

            if(vrstica.size()!=8){
                continue;
            }

            try{
                date1 = Date::GetDateFromString(vrstica[3]);
                students.push_back(std::make_shared<Student>(std::stoi(vrstica[0]), vrstica[1], vrstica[2], date1,
                                                             Address(vrstica[4], vrstica[5], vrstica[6]), vrstica[7]));
            }catch (UnparseableDateException &exception) {
                std::cout << exception.what() << std::endl;
                date1 = {};
            }catch(WrongPhoneNumberException &exception){
                std::cout << exception.what() << std::endl;
            }
        }
        f.close();
        return students;
    }
}

void Student::SaveToFile(const std::vector<std::shared_ptr<Student>> &students, const std::string &fileName) {
    std::ofstream f(fileName);
    if (!f.is_open()) {
        std::cout << "ERROR";
        return;
    }
    for (int i = 0; i < students.size(); i++) {
        f << students[i]->toString() << "\n";
    }
    f.close();
}
