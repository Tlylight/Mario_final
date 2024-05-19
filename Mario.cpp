// Mario.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

