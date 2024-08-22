//
//  main.cpp
//  tictactoe
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "TicTacToeField.hpp"
#include "TicTacToeGame.hpp"

using namespace std;

void delete_output_lines(int num_line) {
    for(int i = 0; i < num_line; i++) {
        // move cursor up one line and clear it
        std::cout << "\033[F\033[K";
    }
}


int main(int argc, const char * argv[]) {
    cout << "Commandline TicTacToe " << endl;
    cout << endl;

    string  player1 = "";
    string  player2 = "";

    cout << "Player 1, please enter your name: " << endl;
    cin >> player1;
    delete_output_lines(2);

    cout << "And Player 2, please enter your name as well: " << endl;
    cin >> player2;
    delete_output_lines(2);

    cout << "The players are: " << player1 << " vs " << player2 << endl;

    TicTacToeGame g(player1, player2);

    //cout << g.getFieldString() << endl;

    while (!g.isFinished()) {
        cout << g.getFieldString() << endl;
        cout << g.getCurrentPlayer() << ", enter your move (column row): " << endl;
        int row, col;
        string row_string;
        string col_string;

        cin >> col_string >> row_string;

        // check input is correct
        std::stringstream ss(row_string);
        int number;
        ss >> number;

        if(!ss.fail()){
            row = number - 1;
        }
        else {row = -1;}

        if (col_string == "a"){col = 0;}
        else if (col_string == "b"){col = 1;}
        else if (col_string == "c"){col = 2;}
        else {col = -1;}

        // play the game
        try {
            g.play(row, col);
        } catch (exception &e) {
            cout << "This move is invalid, please try again." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "\033[F\033[K";
        }
        delete_output_lines(7);
    }
    cout  << g.getWinner() << " won the match! Congratulations!!" << endl;
    return 0;
}
