#include "Game.h"
#include "Resouces.h"
#include "Map.h"
#include <filesystem>

Map map(16.0f);
Camera camera(320.0f);

const float movementspeed = 200.0f;
void Begin(const sf::Window& window)
{
	for (auto& file : std::filesystem::directory_iterator("./resouces/textures/"))
	{
		if (file.is_regular_file() && (file.path().extension() == ".png"
			|| file.path().extension() == ".jpeg" || file.path().extension() == ".jpg"))
		{
			Resouces::textures[file.path().filename().string()].loadFromFile(
				file.path().string());
		}
	}
	sf::Image image;
	image.loadFromFile("map.png");
	map.CreateFromImage(image);
	//map.CreateCheckerboard(10, 10);
	camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Update(float deltaTime)
{
	float move = movementspeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		move *= 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camera.position.x += move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camera.position.x -= move * deltaTime;
}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
}
