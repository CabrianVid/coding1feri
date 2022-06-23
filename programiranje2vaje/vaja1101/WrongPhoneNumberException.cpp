//
// Created by LENOVO on 31. 05. 2022.
//

#include "WrongPhoneNumberException.h"

WrongPhoneNumberException::WrongPhoneNumberException(std::string& temp) : message("WrongPhoneNumber:" + temp) {
}

const char *WrongPhoneNumberException::what() const noexcept {
    return message.data();
}