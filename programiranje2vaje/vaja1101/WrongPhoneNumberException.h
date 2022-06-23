//
// Created by LENOVO on 31. 05. 2022.
//

#ifndef VAJA1101_WRONGPHONENUMBEREXCEPTION_H
#define VAJA1101_WRONGPHONENUMBEREXCEPTION_H


#include <string>

class WrongPhoneNumberException : public std::exception{
private:
    std::string message;
public:
    explicit WrongPhoneNumberException(std::string& temp);
    const char* what() const noexcept;
};


#endif //VAJA1101_WRONGPHONENUMBEREXCEPTION_H
