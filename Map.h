#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "renderer.h"

class Map
{
public:
	Map(float cellsize = 32.0f);
	void CreateCheckerboard(size_t width, size_t height);
	sf::Vector2f CreateFromImage(const sf::Image& image);
	void Draw(Renderer& renderer);
	std::vector<std::vector<int>> grid;
	float cellsize;

};

