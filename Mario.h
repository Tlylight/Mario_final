#pragma once

#include <SFML/Graphics.hpp>
#include "renderer.h"
class Mario
{
public:
	void Begin();
	void Update(float deltaTime);
	void Draw(Renderer& renderer);
	sf::Vector2f position{};
	float angle{};
};
