//
// Created by anton on 19.04.19.
//

#include "Token.h"

Token::Token(TokenType type, const std::string &data) : type(type), data(data) {}

TokenType Token::getType() const {
    return type;
}

void Token::setType(TokenType type) {
    Token::type = type;
}

const std::string &Token::getData() const {
    return data;
}

void Token::setData(const std::string &data) {
    Token::data = data;
}
