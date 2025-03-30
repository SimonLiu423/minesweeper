#include <vector>

using namespace std;

struct Cell {
    bool has_mine;
    int adj_mines;
    Cell(bool _has_mine, int _adj_mines) : has_mine(_has_mine), adj_mines(_adj_mines) {}
};

class Minesweeper {
   private:
    int rows, cols;
    int n_mines;
    bool is_revealed;
    vector<vector<Cell> > grid;
    void place_mine();
    void remove_mine(int row, int col);

   public:
    void generate_board(int rows, int cols, int n_mines);
    int reveal(int row, int col);
    void display_mines();
};