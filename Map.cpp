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
				renderer.Draw(Resouces::textures["sopdog.jpg"], sf::Vector2f(cellsize * x + cellsize / 2.0f, cellsize *y + cellsize / 2.0f), sf::Vector2f(cellsize, cellsize));
			}
			y++;
		}
		x++;
	}
}
