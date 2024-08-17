//
//  InvalidMove.hpp
//  tictactoe
//

#pragma once

#include <stdexcept>

class InvalidMove : public std::exception {
public:
    virtual const char* what() const noexcept;
};
