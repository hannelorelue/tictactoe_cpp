//
//  main.cpp
//  tictactoe
//

#include <iostream>
#include <string>
#include <vector>

#include "TicTacToeField.hpp"
#include "TicTacToeGame.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    TicTacToeGame g("Adam", "Eve");

    cout << g.getFieldString() << endl;

    while (!g.isFinished()) {
        cout << g.getCurrentPlayer() << ", bitte gebe deine gewünschte Position ein: " << endl;
        int row, col;

        cin >> row >> col;
        try {
            g.play(row, col);
        } catch (exception &e) {
            cout << e.what() << endl;
            cout << "Dieser Spielzug ist ungueltig, bitte versuche es erneut." << endl;
        }

        cout << g.getFieldString() << endl;
    }
    cout << "Der Gewinner ist: " << g.getWinner() << endl;
    return 0;
}
