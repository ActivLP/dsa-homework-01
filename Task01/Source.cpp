#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Flower");
    Flower flower(&window);

    while (window.isOpen())
    {
        sf::Event event;  
        while (window.pollEvent(event))  
        {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }

        window.clear(sf::Color(173, 216, 230));
        flower.drawFlower();
        window.display();
    }

    return 0;
}
