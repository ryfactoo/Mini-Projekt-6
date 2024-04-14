
#ifndef UNTITLED1_INVALIDVALUEINFILE_H
#define UNTITLED1_INVALIDVALUEINFILE_H
#include <exception>
#include <string>


class InvalidValueInFile: public std::exception{

private:
    std::string message;

public:

    explicit InvalidValueInFile(const std::string msg = ""){
        message += msg;
    }


    const char* what()const noexcept override{
        return message.c_str();
    }
};


#endif
