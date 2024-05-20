#include "Game.h"

sf::Texture texture;


void Begin(const sf::Window& window)
{
	if (!texture.loadFromFile("yuki.jpeg"))
		exit(-1);
}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	renderer.Draw(texture, sf::Vector2f(), sf::Vector2f(4.75f, 4.75f));
}
