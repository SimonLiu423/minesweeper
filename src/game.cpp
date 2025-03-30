#include "game.h"

#include <iostream>

static inline bool index_in_range(int row, int col, int n_row, int n_col) {
    return row >= 0 && row < n_row && col >= 0 && col < n_col;
}

void Minesweeper::generate_board(int rows, int cols, int n_mines) {
    // Set game properties
    this->rows = rows;
    this->cols = cols;
    this->n_mines = n_mines;

    // Initialize grid
    grid.resize(rows, vector<Cell>(cols, Cell(false, 0)));

    // Randomly place mines
    srand(time(NULL));
    int placed_mines = 0;

    while (placed_mines < n_mines) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (!grid[r][c].has_mine) {
            // If there is no mine, place one
            grid[r][c].has_mine = true;
            placed_mines++;

            // Update adjacent cells
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (index_in_range(nr, nc, rows, cols) && !grid[nr][nc].has_mine) {
                        grid[nr][nc].adj_mines++;
                    }
                }
            }
        }
    }
}
