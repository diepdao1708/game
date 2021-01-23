#pragma once
#include <SFML/Graphics.hpp>
#include "Attribute.h"

enum Tag
{
	Tag_Ball=0,
	Tag_PointBlock,
	Tag_Null,
};
class Entity:public Attribute
{
public:
	Entity();
	~Entity();
	bool isActive();
	void setActive(bool isActive);
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f newVelocity);
	void setTag(Tag newTag);
	Tag getTag();
	Tag getCollider();
	void SetCollider(Tag newCollider);
	int getNumCollider();
	void setNumCollider(int num);
protected:
	bool m_isActive;
	sf::Vector2f m_Velocity;
	Tag m_Tag;
	Tag m_Collider;
	int m_NumCollider;

};