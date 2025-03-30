#include "game.h"

#include <iostream>

static inline bool index_in_range(int row, int col, int n_row, int n_col) {
    return row >= 0 && row < n_row && col >= 0 && col < n_col;
}

void Minesweeper::place_mine() {
    int r, c;
    do {
        r = rand() % rows;
        c = rand() % cols;
    } while (grid[r][c].has_mine);  // Choose another cell if mine already exists

    // Place mine
    grid[r][c].has_mine = true;

    // Update adjacent cells
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int nr = r + dr;
            int nc = c + dc;
            if (index_in_range(nr, nc, rows, cols)) {
                grid[nr][nc].adj_mines++;
            }
        }
    }
}

void Minesweeper::remove_mine(int row, int col) {
    // Remove mine
    grid[row][col].has_mine = false;

    // Update adjacent cells
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int nr = row + dr;
            int nc = col + dc;
            if (index_in_range(nr, nc, rows, cols)) {
                grid[nr][nc].adj_mines--;
            }
        }
    }
}

void Minesweeper::generate_board(int rows, int cols, int n_mines) {
    // Initialize Minesweeper
    *this = Minesweeper(rows, cols, n_mines);

    // Initialize grid
    grid.resize(rows, vector<Cell>(cols, Cell(false, 0)));

    // Randomly place mines
    int placed_mines = 0;

    while (placed_mines < n_mines) {
        place_mine();
        placed_mines++;
    }
}

int Minesweeper::reveal(int row, int col) {
    if (!is_revealed && grid[row][col].has_mine) {
        remove_mine(row, col);
        place_mine();
    }
    is_revealed = true;
    return grid[row][col].adj_mines;
}

void Minesweeper::display_mines() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j].has_mine << ' ';
        }
        cout << endl;
    }
    cout << endl;
}