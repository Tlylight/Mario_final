#include "Game.h"
#include "Resouces.h"

#include <filesystem>
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
}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	renderer.Draw(Resouces::textures["sopdog.jpg"], sf::Vector2f(), sf::Vector2f(4.75f, 4.75f));
}
