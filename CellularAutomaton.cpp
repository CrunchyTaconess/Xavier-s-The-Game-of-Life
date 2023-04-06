// CellularAutomaton.cpp
#include "CellularAutomaton.h"
#include <ctime>
#include <cstdlib>

// CONSTRUCTOR: Initialize the cellular automaton with the given dimensions
CellularAutomaton::CellularAutomaton(int width, int height, int cellSize)
    : width(width), height(height), cellSize(cellSize),
    grid(width, std::vector<bool>(height, false)),
    newGrid(width, std::vector<bool>(height, false)) {
    //Initialize the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));
}

//Randomize grid with rando live and dead cells
void CellularAutomaton::randomizeGrid() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            grid[x][y] = rand() % 2;
        }
    }
}

// Update the grid according to the Game of Life rules
void CellularAutomaton::updateGrid() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int aliveNeighbors = countAliveNeighbors(x, y);
            // Game of Life rules:
            // 1. Any live cell with two or three live neighbors survives.
            if (grid[x][y] && (aliveNeighbors == 2 || aliveNeighbors == 3)) {
                newGrid[x][y] = true;
            }
            // 2. Any dead cell with exactly three live neighbors becomes a live cell.
            else if (!grid[x][y] && aliveNeighbors == 3) {
                newGrid[x][y] = true;
            } 
            // 3. All other live cells die in the next generation. Similarly, dead cells stay dead.
            else {
                newGrid[x][y] = false;
            }
        }
    }

    // Swap the current grid with the updated grid
    grid.swap(newGrid);
}


// Get the state of a cell at the specified position (alive or dead)
bool CellularAutomaton::getCellState(int x, int y) const {
    return grid[x][y];
}

// Count the number of alive neighbors for a cell at the specified position
int CellularAutomaton::countAliveNeighbors(int x, int y) const {
    int aliveNeighbors = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // Skip the cell itself
            if (i == 0 && j == 0) continue;

            int newX = (x + i + width) % width;
            int newY = (y + j + height) % height;

            aliveNeighbors += grid[newX][newY];
        }
    }

    return aliveNeighbors;
}

