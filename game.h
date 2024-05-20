#pragma once
#include <SFML/Graphics.hpp>
#include "renderer.h"

void Begin(const sf::Window& window);
void Update(float deltaTime);
void Render(Renderer& renderer);
