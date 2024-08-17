//
//  TicTacToeGame.cpp
//  tictactoe
//

#include <iostream>
#include <sstream>

#include "TicTacToeGame.hpp"
#include "InvalidMove.hpp"



using  namespace std;

TicTacToeGame::TicTacToeGame(string player1, string player2){
    this->player1_ = player1;
    this->player2_ = player2;

    currentPlayer_ = 1;
    cout << "TicTacToeGame" << endl;
}

string TicTacToeGame::getFieldString() {
    stringstream output;

    output << "Player 1: " << player1_ << endl;
    output << "Player 2: " << player2_ << endl;

    output << TicTacToeField::getFieldString();
    return output.str();
}

void TicTacToeGame::play(int row, int col){
    if(row < 0 || row >= field.size() || col < 0 || col >= field[row].size()){
        throw InvalidMove();
    }
    if(field[row][col] == 0){
        this->field[row][col] = currentPlayer_;
        if (currentPlayer_ == 1) {
            currentPlayer_ = 2;
        }
        else {
            currentPlayer_ = 1;
        }
    } else {
        throw InvalidMove();
    }
}

bool TicTacToeGame::isFinished() {
    int winner = calculateWinner();
    if (winner != 0) {
        return true;
    }
    for(const auto &row : field){
        for(const int &value : row){
            if(value == 0){
                return false;
            }
        }
    }
    return true;
}



string TicTacToeGame::getCurrentPlayer() {
    if(currentPlayer_ == 1) {return  player1_; }
    else {return player2_;}
}

string TicTacToeGame::getWinner() {
    if(isFinished()) {
        int winner = calculateWinner();
        if (winner == 0) {
            return "Unentschieden";
        } else if (winner == 1){
            return  player1_;
        } else{
            return player2_;
        }
    }
    return "";
}
