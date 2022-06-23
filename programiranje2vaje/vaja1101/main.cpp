
#include <iostream>
#include "Date.h"
#include "Student.h"
#include "UnparseableDateException.h"

int main() {
    try{
        std::cout<<Date::GetDateFromString(Date(10,10,2022).toString()).toString();
        std::cout<<Date::GetDateFromString("12.1o.2022").toString();
        std::cout<<Date::GetDateFromString("33.12.2022").toString();
    }    catch (UnparseableDateException &exception) {
    std::cout<<exception.what()<<std::endl;
    }
    std::vector<std::shared_ptr<Student>> students = Student::LoadFromFile("students.csv");

    for(int i=0;i<students.size();i++){
        std::cout<< students[i]->toString()<<"\n";
    }
    Student::SaveToFile(students, "output.txt");
    Student::SaveToFile(Student::LoadFromFile("students.csv"), "output3.txt");

    return 0;
}
