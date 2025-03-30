#include <vector>

using namespace std;

struct Cell {
    bool has_mine;
    int adj_mines;
    Cell() : has_mine(false), adj_mines(0) {}
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
    Minesweeper() : rows(0), cols(0), n_mines(0), is_revealed(false) {}
    Minesweeper(int _rows, int _cols, int _n_mines) : rows(_rows), cols(_cols), n_mines(_n_mines), is_revealed(false) {}
    void generate_board(int rows, int cols, int n_mines);
    int reveal(int row, int col);
    void display_mines();
    void display_adj();
};