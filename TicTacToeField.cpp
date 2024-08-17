//
//  tictactoeField.cpp
//  tictactoe
//

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "TicTacToeField.hpp"

using namespace std;


TicTacToeField::TicTacToeField() {
    field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
}

int TicTacToeField::calculateWinner() {
    for (int i = 0; i <= 2; i++) {
        if (field.at(i).at(0) != 0 &&
            field.at(i).at(0) == field.at(i).at(1) &&
            field.at(i).at(0) == field.at(i).at(2)) {

            return field.at(i).at(0);
        }
    }

    for (int i = 0; i <= 2; i++) {
        if (field.at(0).at(i) != 0 &&
            field.at(0).at(i) == field.at(1).at(i) &&
            field.at(0).at(i) == field.at(2).at(i)) {

            return field.at(0).at(i);
        }
    }

    if (field.at(0).at(0) != 0 &&
        field.at(0).at(0) == field.at(1).at(1) &&
        field.at(0).at(0) == field.at(2).at(2)) {

        return field.at(0).at(0);
    }

    if (field.at(0).at(2) != 0 &&
        field.at(0).at(2) == field.at(1).at(1) &&
        field.at(0).at(2) == field.at(2).at(0)) {

        return field.at(0).at(2);
    }

    return 0;
}

string TicTacToeField::getFieldString() {
    stringstream output;

    for (const auto &row : field) {
        output << " | ";
        for (const auto &item : row) {
            output << item << " | ";
        }
        output << endl;
    }
    return output.str();
}

