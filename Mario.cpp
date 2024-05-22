// Mario.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>
#include "SFML/Graphics.hpp"
int main()
{
    std::cout << "Hello World!\n";
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    sf::Event e;
    
    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
    }

}
*/
#include <SFML/Graphics.hpp>
#include "game.h"
#include "camera.h"
#include "renderer.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Mario World");
    sf::Clock deltaClock;
    Renderer renderer(window);
    
    Begin(window);
    while (window.isOpen()) 
    {
        float deltaTime = deltaClock.restart().asSeconds();

        sf::Event event{};
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.setView(camera.GetView(window.getSize()));
        Update(deltaTime);
       
        window.clear(sf::Color::Blue);
        Render(renderer);
        window.display();

    }
}
