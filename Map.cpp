#include "Map.h"
#include "renderer.h"
#include "Resouces.h"

Map::Map(float cellsize) : cellsize(cellsize), grid()
{

}

void Map::CreateCheckerboard(size_t width, size_t height)
{
	grid = std::vector(width, std::vector(height, 0));

	int last = 0;
	for (auto& column : grid)
	{
		for (auto& cell : column)
		{
			cell = ~last;
			last = cell;
		}
		if (width % 2 == 0)
			last = ~last;
	}
}

void Map::Draw(Renderer& renderer)
{
	int x = 0;
	for (const auto& column : grid)
	{
		int y = 0;
		for (const auto& cell : column)
		{
			if (cell)
			{
				renderer.Draw(Resouces::textures["brick.png"], sf::Vector2f(cellsize * x + cellsize / 2.0f, cellsize *y + cellsize / 2.0f), sf::Vector2f(cellsize, cellsize));
			}
			y++;
		}
		x++;
	}
}

sf::Vector2f Map::CreateFromImage(const sf::Image& image)
{
	grid.clear();
	grid = std::vector(image.getSize().x, std::vector(image.getSize().y, 0));
	sf::Vector2f MarioPosition;
	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			sf::Color color = image.getPixel(x, y);
			if (color == sf::Color::Black)
				grid[x][y] = 1;
			else if (color == sf::Color::Red)
				MarioPosition = sf::Vector2f(cellsize * x + cellsize / 2.0f, cellsize * y + cellsize / 2.0f);

		}
	}
	return MarioPosition;
}
