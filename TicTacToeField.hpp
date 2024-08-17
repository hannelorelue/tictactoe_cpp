//
//  TicTacToeField.h
//  tictactoe
//

#pragma once


#include <vector>
#include <string>
#include <sstream>


class TicTacToeField {
protected:
    std::vector<std::vector<int>> field;

public:
    TicTacToeField();

    int calculateWinner();

    std::string getFieldString();
};

