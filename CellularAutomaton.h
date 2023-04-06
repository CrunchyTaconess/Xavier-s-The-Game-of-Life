// CellularAutomaton.h
#pragma once
#include <vector>

class CellularAutomaton {
public:
    //CONSTRUCTOR:Initial Dimensions
    CellularAutomaton(int width, int height, int cellSize);

    //Initialize Grid with Dead and live cells(Random)
    void randomizeGrid();

    //Update grid according to the rules
    void updateGrid();

    //Get state of a cell at the specified position (alive or dead)
    bool getCellState(int x, int y) const;

private:
    //Grid Dimensions and cell size
    int width;
    int height;
    int cellSize;

    // Grid containing the current state of each cell
    std::vector<std::vector<bool>> grid;

    // Temporary grid used for updating the cellular automaton
    std::vector<std::vector<bool>> newGrid;

    // Count the number of alive neighbors for a cell at the specified position
    int countAliveNeighbors(int x, int y) const;
};

