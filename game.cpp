#include "Game.h"
#include "Resouces.h"
#include "Map.h"
#include <filesystem>
#include "Mario.h"
#include "Physics.h"
Map map(16.0f);
Camera camera(320.0f);
Mario mario;

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
	Physics::Init();

	sf::Image image;
	image.loadFromFile("map.png");
	mario.position = map.CreateFromImage(image);
	mario.Begin();

	//map.CreateCheckerboard(10, 10);
	//camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Update(float deltaTime)
{
	Physics::Update(deltaTime);
	mario.Update(deltaTime);
	camera.position = mario.position;	
}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
	mario.Draw(renderer);
}
