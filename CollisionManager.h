#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Ball.h"
#include "PointBlock.h"

using namespace std;
using namespace sf;
enum CollisionDir
{
	NO = 0,
	top = 1,
	bottom = 2,
	Left = 3,
	Right = 4,
	top_left = 5,
	top_right = 6,
	bottom_left = 7,
	bottom_right = 8,
	top_wall = 9,
	bottom_wall = 10,
	left_wall = 11,
	right_wall = 12
};

class CollisionManager
{
	std::vector<Entity*> m_ListObject;
public:
	static CollisionDir Check(sf::CircleShape ball, sf::RectangleShape shape);
	static CollisionDir Check(Ball &ball, PointBlock &shape);
	static Vector2f getVelocity(sf::CircleShape ball, sf::RectangleShape shape, Vector2f velocity);
	static Vector2f getVelocity(Ball &ball, PointBlock &shape, Vector2f velocity);
	void Push(Entity& entiy);
	void Update(float deltaTime);

};