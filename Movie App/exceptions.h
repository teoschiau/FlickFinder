//
// Created by Teodora Schiau on 09.04.2024.
//

#ifndef OOP_A6_7_916_SCHIAU_TEODORA_EXCEPTIONS_H
#define OOP_A6_7_916_SCHIAU_TEODORA_EXCEPTIONS_H

#include <exception>
#include <utility>
#include <string>


using namespace std;
class Exceptions: public exception
{
protected:
    string msg;

public:
    explicit Exceptions(string Exceptionmsg);
    const char* what() const noexcept override;
};

class ExceptionRepo: public Exceptions
{
public:
    explicit ExceptionRepo(string Message);
};

class ExceptionsValidator: public Exceptions
{
public:
    explicit ExceptionsValidator(string MessageException);
};



#endif //OOP_A6_7_916_SCHIAU_TEODORA_EXCEPTIONS_H
