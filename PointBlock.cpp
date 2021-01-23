#include "PointBlock.h"

PointBlock::PointBlock()
{
	this->setSize(sf::Vector2f(100, 100));
	this->setPosition(400, 400);
	this->setOrigin(this->getSize() * 0.5f);
	this->setHp(30);
	setTag(Tag_PointBlock);
}

PointBlock::~PointBlock()
{
}

void PointBlock::Init(float x, float y)
{
	this->setPosition(sf::Vector2f(x, y));
	m_Font.loadFromFile("font.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(sf::Vector2f(this->getPosition().x-28, this->getPosition().y-30));
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setCharacterSize(50);
	m_Text.setOutlineThickness(1);
	m_Text.setOutlineColor(sf::Color::Black);
	texture.loadFromFile("shape.png");
	s.setTexture(texture);
	s.setOrigin(sf::Vector2f(texture.getSize().x * 0.5f, texture.getSize().y * 0.5f));
	s.setPosition(this->getPosition());
	s.setScale(1, 1);
}

void PointBlock::Update(float deltaTime)
{
	if (getHp() <= 0) setActive(false);
	m_Text.setString(this->getStringHp());
}

void PointBlock::Draw(sf::RenderWindow& window)
{
	if (!isActive()) return;
	window.draw(*this);
	window.draw(s);
	window.draw(m_Text);
	
}
