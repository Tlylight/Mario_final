#pragma once
#include <Box2d/include/box2d/b2_body.h>
class Physics
{
public:
	static void Init();
	static void Update(float deltaTime);
private:
	static b2World world;

};

