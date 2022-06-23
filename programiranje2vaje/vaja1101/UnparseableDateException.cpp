//
// Created by LENOVO on 27. 05. 2022.
//

#include "UnparseableDateException.h"

UnparseableDateException::UnparseableDateException(std::string& temp) : message("Unparseable date:" + temp) {
}

const char *UnparseableDateException::what() const noexcept {
    return message.data();
}