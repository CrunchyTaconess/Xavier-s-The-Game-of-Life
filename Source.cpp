//Xavier Alers
#include "CellularAutomaton.h"
#include <SFML/Graphics.hpp>

int main() {
    //Window size & Cell Size
    int width = 1920;
    int height = 1080;
    int cellSize = 10;
    
    //Window Settings 
    sf::RenderWindow window(sf::VideoMode(width, height), "Game of Life"); 
    window.setFramerateLimit(60);

    // Create a CellularAutomaton Simulation with the desired grid dimensions
    CellularAutomaton automaton(width / cellSize, height / cellSize, cellSize);

    //Initial state of grid(Random)
    automaton.randomizeGrid(); 

    //Cell Shape for live cells
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setFillColor(sf::Color::Green);

    //Main Simulation Loop
    while (window.isOpen()) {
        //Process window Events
        sf::Event event;
        while (window.pollEvent(event)) {
            //Close the Window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //Update the Grid
        automaton.updateGrid();
        //Clear every update
        window.clear();

        //Draw live cells on the window
        for (int x = 0; x < width / cellSize; ++x) {
            for (int y = 0; y < height / cellSize; ++y) {
                //If cell is alive, draw it
                if (automaton.getCellState(x, y)) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }

        //Display updated content
        window.display();
    }

    //Exit the Program
    return 0;
}
