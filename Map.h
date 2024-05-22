#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "renderer.h"

class Map
{
public:
	Map(float cellsize = 32.0f);
	void CreateCheckerboard(size_t width, size_t height);
	void Draw(Renderer& renderer);
	void CreateFromImage(const sf::Image& image);

	std::vector<std::vector<int>> grid;
	float cellsize;

};

