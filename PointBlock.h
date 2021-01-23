#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class PointBlock: public sf::RectangleShape, public Entity
{
public:
	PointBlock();
	~PointBlock();
	void Init(float x, float y);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
private:
	sf::Texture texture;
	sf::Sprite s;
	sf::Font m_Font;
	sf::Text m_Text;
};