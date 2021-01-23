#pragma once
#include <SFML/Graphics.hpp>
class MovingDirect
{
public:
	MovingDirect();
	~MovingDirect();
	void Update(sf::Vector2f pointA,sf::Vector2f pointB);
	void Update(sf::Vector2f pointB);
	sf::Vector2f getVectorUnit();
	float getAngle();
	void setPointA(sf::Vector2f a);
private:
	float m_Angle;
	sf::Vector2f m_VectorUnit;
	sf::Vector2f m_PointA;
};