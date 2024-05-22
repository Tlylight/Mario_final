#pragma once
#include <SFML/Graphics.hpp>
#include "renderer.h"
#include "camera.h"

extern Camera camera;

void Begin(const sf::Window& window);
void Update(float deltaTime);
void Render(Renderer& renderer);
