# Minesweeper Game

A simple command-line implementation of the classic Minesweeper game in C++.

## Description

This project implements a basic [Minesweeper](https://en.wikipedia.org/wiki/Minesweeper_(video_game)) game that runs in the terminal.

## Features

- Configurable board size (rows, columns)
- Adjustable number of mines
- First-click protection (first clicked cell will never contain a mine)
- Display of mine locations and adjacent mine counts (for debugging/development)

## Requirements

- C++ compiler with C++11 support
- Make (for building with the provided Makefile)

## Building the Game

To build the game, run:

```bash
make
```

This will compile the source code and generate the executable `main.out`.

## Running the Game

To run the game:

```bash
./main.out
```

Upon running, you will be prompted to enter:
1. Number of rows
2. Number of columns
3. Number of mines

Then, for each move, enter:
- Row index
- Column index

The game will display all mines and number of adjacent mines on the board.

## Project Structure

- `src/game.h` - Header file containing class definitions
- `src/game.cpp` - Implementation of the Minesweeper game logic
- `src/main.cpp` - Main program that handles user input and game flow
- `Makefile` - Build configuration

## Future Improvements

Potential improvements for the game include:
- Better user interface
- Auto-reveal of adjacent empty cells
- Cell flagging functionality
- Game state tracking (win/lose conditions)
- More efficient mine placement algorithm for large boards
- Improved randomization
- Save/load game functionality

## Cleaning Up

To clean the project directory (remove compiled files):

```bash
make clean
```

## License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0) - see the [GNU GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html) for details.
