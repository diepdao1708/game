#pragma once
#include "SFML/Graphics.hpp"

class NextLevel
{
private:
	sf::Sprite s1, s2, s3, s4, s5, s6, s7, win, nen, lose;
	sf::Texture texture1, texture2, texture3, texture4, texture5, texture6, texture7,
		textureWin, textureNen, textureLose;
public:
	void DrawLevel1(sf::RenderWindow& window);
	void DrawLevel2(sf::RenderWindow& window);
	void DrawLevel3(sf::RenderWindow& window);
	void DrawLevel4(sf::RenderWindow& window);
	void DrawLevel5(sf::RenderWindow& window);
	void DrawLevel6(sf::RenderWindow& window);
	void DrawLevel7(sf::RenderWindow& window);
	void DrawWin(sf::RenderWindow& window);
	void DrawLose(sf::RenderWindow& window);
};