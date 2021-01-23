#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Attribute.h"

class Ball:public sf::CircleShape,public Entity
{
public:
	void Init();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void setIsFire(bool isFire);
	bool isFire();
	void Fire();
	void setDirect(sf::Vector2f unit);
private:
	sf::Vector2f m_VectorDirect;
	sf::Texture texture;
	sf::Sprite s;
	bool m_isFire;
	float m_Speed;
};