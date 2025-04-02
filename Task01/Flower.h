#pragma once
#include <SFML/Graphics.hpp>

class Flower
{
    private:
        sf::RenderWindow* window;

        sf::Clock frameClock;
        float sunSize;
        bool increase;

        // bonus content 
        sf::CircleShape cloud, cloud2;
        float CloudPosX;
        float CloudSpeed;

    public:
        Flower(sf::RenderWindow* window);
        ~Flower();

        void drawFlower();

};