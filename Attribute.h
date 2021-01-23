#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Attribute
{
public:
	void setHp(int hp);
	int getHp();
	std::string getStringHp();
	void LoseHP(int offset);
	void Init();
	void Update(float detalTime);
	void Draw(sf::RenderWindow &window);
private:
	int m_Hp;
};