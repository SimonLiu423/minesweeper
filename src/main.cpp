#include <ctime>
#include <iostream>

#include "game.h"
using namespace std;

int main() {
    Minesweeper game;
    int rows, cols, mines;

    srand(time(NULL));

    cin >> rows >> cols >> mines;

    game.generate_board(rows, cols, mines);
    game.display_mines();
    game.display_adj();
    while (true) {
        int r, c;
        cin >> r >> c;
        cout << game.reveal(r, c) << endl;
        game.display_mines();
        game.display_adj();
    }
}