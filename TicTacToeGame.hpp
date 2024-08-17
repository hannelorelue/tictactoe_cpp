//
//  TicTacToeGame.hpp
//  tictactoe
//

#pragma once

#include "TicTacToeField.hpp"
#include <string>

class TicTacToeGame: public TicTacToeField {
private:
    std::string player1_;
    std::string player2_;
    int currentPlayer_;
public:
    TicTacToeGame(std::string player1, std::string player2);
    bool isFinished();
    std::string getFieldString();
    void play(int row, int col);
    std::string getCurrentPlayer();
    std::string getWinner();
};
