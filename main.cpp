#include <SFML/Graphics.hpp>
#include "Grid.hpp"

using namespace sf;

int numCells = 500;
int width = 1000;
int height = 1000;

int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    Grid grid(numCells, width, height);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}