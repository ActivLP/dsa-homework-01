#include "Flower.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flower::Flower(sf::RenderWindow* window)
{
    this->window = window;

    sunSize = 25.f;
    increase = true;

    CloudPosX = -10.f;
    CloudSpeed = 0.05f;

    cloud.setRadius(50.f);
    cloud.setScale({ 1.5f, 0.5f });
    cloud.setFillColor(sf::Color::White);

    cloud2.setRadius(60.f);
    cloud2.setScale({ 1.f, 0.5f });
    cloud2.setFillColor(sf::Color::White);
}

Flower::~Flower()
{
    std::cout << "Flower destroyed" << std::endl;
}

void Flower::drawFlower()
{

    // sun animation 
    if (frameClock.getElapsedTime().asSeconds() > 0.05f)
    {
        if (increase)
        {
            sunSize += 0.1f;
            if (sunSize >= 20.f) increase = false;
        }
        else
        {
            sunSize -= 0.1f;
            if (sunSize <= 15.f) increase = true;
        }
        frameClock.restart();
    }

    // sun
    sf::CircleShape sun(sunSize);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition({ 50, 60 });

    // cloud
    CloudPosX += CloudSpeed;
    if (CloudPosX > 800) CloudPosX = -100;
    cloud.setPosition({ CloudPosX, 100 });
    cloud2.setPosition({ CloudPosX * 1.5f, 10 });

    // grass
    sf::RectangleShape grass({ 800.f, 100.f });
    grass.setFillColor(sf::Color(34, 139, 34));
    grass.setPosition({ 0, 720 });

    // petals
    sf::CircleShape petal(70.f);
    petal.setFillColor(sf::Color::White);
    petal.setPosition({ 350,300 });
    petal.setOutlineThickness(30.f);
    petal.setOutlineColor(sf::Color::Blue);

    // stem
    sf::RectangleShape stem({ 300.f, 15.f });
    stem.setRotation(sf::degrees(90));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition({ 427, 468 });

    // leafs
    sf::ConvexShape leaf;
    leaf.setPointCount(4);
    leaf.setFillColor(sf::Color::Green);
    leaf.setPoint(0, { 100.f, 30.f }); // up
    leaf.setPoint(1, { 200.f, 30.f }); // right
    leaf.setPoint(2, { 130.f, 100.f }); // down
    leaf.setPoint(3, { 30.f, 100.f }); // left
    leaf.setPosition({ 395, 600 });

    sf::ConvexShape leaf2;
    leaf2 = leaf;
    leaf2.rotate(sf::degrees(-120));
    leaf2.setPosition({ 350, 700 });

    // draw all
    window->draw(sun);
    window->draw(cloud);
    window->draw(cloud2);
    window->draw(grass);
    window->draw(petal);
    window->draw(stem);
    window->draw(leaf);
    window->draw(leaf2);
}
