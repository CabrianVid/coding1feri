//
// Created by LENOVO on 27. 05. 2022.
//

#ifndef VAJA1101_UNPARSEABLEDATEEXCEPTION_H
#define VAJA1101_UNPARSEABLEDATEEXCEPTION_H

#include <exception>
#include <string>


class UnparseableDateException : public  std::exception{
private:
    std::string message;
public:
    explicit UnparseableDateException(std::string& temp);
    const char* what() const noexcept;

};


#endif //VAJA1101_UNPARSEABLEDATEEXCEPTION_H
