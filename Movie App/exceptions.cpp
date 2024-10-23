//
// Created by Teodora Schiau on 09.04.2024.
//

#include "exceptions.h"

Exceptions::Exceptions(std::string Exceptionmsg) {
    this->msg = move(Exceptionmsg);
}

const char *Exceptions::what() const noexcept {
    return this->msg.c_str();
}

ExceptionRepo::ExceptionRepo(string Message):Exceptions(move(Message)){
}

ExceptionsValidator::ExceptionsValidator(string MessageException) : Exceptions(move(MessageException)) {

}

