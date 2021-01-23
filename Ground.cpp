#include "Ground.h"


void Ground::Init()
{
	player.Init(6);
	texture.loadFromFile("Gound.png");
	s.setTexture(texture);
	texture1.loadFromFile("play.png");
	s1.setTexture(texture1);
	s1.setOrigin(sf::Vector2f(texture1.getSize().x * 0.5f, texture1.getSize().y * 0.5f));
	s1.scale(Vector2f(7, 7));
	s1.setPosition(Vector2f(350, 725));
	texture2.loadFromFile("play1.png");
	s2.setTexture(texture2);
	s2.setOrigin(sf::Vector2f(texture2.getSize().x * 0.5f, texture2.getSize().y * 0.5f));
	s2.scale(Vector2f(1, 1));
	s2.setPosition(Vector2f(350, 725));
}

void Ground::Update(float deltaTime)
{
	player.Move(sf::Vector2f(220, 0), deltaTime);
	player.Update();
}

void Ground::Draw(sf::RenderWindow& rd)
{
	rd.draw(s);
	rd.draw(s1);
	rd.draw(s2);
	player.Draw(rd);
}

void Ground::DrawPlay(RenderWindow& rd)
{
	texturePlay.loadFromFile("nen.png");
	backgroundplay.setTexture(texturePlay);
	backgroundplay.setScale(1.55, 1.55);
	rd.draw(backgroundplay);
}


