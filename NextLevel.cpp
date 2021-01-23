#include "NextLevel.h"

void NextLevel::DrawLevel1(sf::RenderWindow& window)
{
	texture1.loadFromFile("level1.png");
	s1.setTexture(texture1);
	s1.setOrigin(sf::Vector2f(texture1.getSize().x * 0.5f, texture1.getSize().y * 0.5));
	s1.setPosition(sf::Vector2f(350, 400));
	s1.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s1);
}

void NextLevel::DrawLevel2(sf::RenderWindow& window)
{
	texture2.loadFromFile("level2.png");
	s2.setTexture(texture2);
	s2.setOrigin(sf::Vector2f(texture2.getSize().x * 0.5f, texture2.getSize().y * 0.5));
	s2.setPosition(sf::Vector2f(350, 400));
	s2.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s2);
}

void NextLevel::DrawLevel3(sf::RenderWindow& window)
{
	texture3.loadFromFile("level3.png");
	s3.setTexture(texture3);
	s3.setOrigin(sf::Vector2f(texture3.getSize().x * 0.5f, texture3.getSize().y * 0.5));
	s3.setPosition(sf::Vector2f(350, 400));
	s3.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s3);
}

void NextLevel::DrawLevel4(sf::RenderWindow& window)
{
	texture4.loadFromFile("level4.png");
	s4.setTexture(texture4);
	s4.setOrigin(sf::Vector2f(texture4.getSize().x * 0.5f, texture4.getSize().y * 0.5));
	s4.setPosition(sf::Vector2f(350, 400));
	s4.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s4);
}

void NextLevel::DrawLevel5(sf::RenderWindow& window)
{
	texture5.loadFromFile("level5.png");
	s5.setTexture(texture5);
	s5.setOrigin(sf::Vector2f(texture5.getSize().x * 0.5f, texture5.getSize().y * 0.5));
	s5.setPosition(sf::Vector2f(350, 400));
	s5.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s5);
}

void NextLevel::DrawLevel6(sf::RenderWindow& window)
{
	texture6.loadFromFile("level6.png");
	s6.setTexture(texture6);
	s6.setOrigin(sf::Vector2f(texture6.getSize().x * 0.5f, texture6.getSize().y * 0.5));
	s6.setPosition(sf::Vector2f(350, 400));
	s6.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s6);
}

void NextLevel::DrawLevel7(sf::RenderWindow& window)
{
	texture7.loadFromFile("level7.png");
	s7.setTexture(texture7);
	s7.setOrigin(sf::Vector2f(texture7.getSize().x * 0.5f, texture7.getSize().y * 0.5));
	s7.setPosition(sf::Vector2f(350, 400));
	s7.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(s7);
}

void NextLevel::DrawWin(sf::RenderWindow& window)
{
	textureWin.loadFromFile("Win.png");
	win.setTexture(textureWin);
	win.setOrigin(sf::Vector2f(textureWin.getSize().x * 0.5f, textureWin.getSize().y * 0.5));
	win.setPosition(sf::Vector2f(350, 400));
	win.setScale(sf::Vector2f(1.5, 1.5));
	win.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(win);
}

void NextLevel::DrawLose(sf::RenderWindow& window)
{
	textureLose.loadFromFile("endgame.png");
	lose.setTexture(textureLose);
	lose.setOrigin(sf::Vector2f(textureLose.getSize().x * 0.5f, textureLose.getSize().y * 0.5));
	lose.setPosition(sf::Vector2f(350, 400));
	lose.setScale(sf::Vector2f(1.5, 1.5));
	lose.setScale(sf::Vector2f(1.5, 1.5));
	window.draw(lose);
}

