#include <SFML/Graphics.hpp>
using namespace sf;
#include "Square.hpp"
#include "square.cpp"
#include <vector>

using namespace std;

Vector2f speed = {3.f, 3.f};

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!"); // creamos una ventana
    Square shape(Vector2f(50.f, 50.f));
    window.setFramerateLimit(120); // el framerate de la pantalla
    vector<Square> rectangulos;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int w = 50;
                    int h = 50;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    Square rec(Vector2f(w, h), x, y);
                    rectangulos.push_back(rec);
                }
                // evento cambiar un cuadrado a color rojo
                if (event.mouseButton.button == Mouse::Right)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    for (auto &r : rectangulos)
                    {
                        // r.click(x,y);
                                        }
                }
            }
        }

        window.clear();
        shape.update();
        shape.drawTo(window);
        for (auto &r : rectangulos)
        {
            r.update();
            r.drawTo(window);
        }
        window.display();
    }

    return 0;
}
