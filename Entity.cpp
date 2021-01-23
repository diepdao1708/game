#include "Entity.h"

Entity::Entity()
{
    m_isActive = true;
    m_Collider = Tag_Null;
    m_NumCollider = 0;
}

Entity::~Entity()
{

}

bool Entity::isActive()
{
    return m_isActive;
}

void Entity::setActive(bool isActive)
{
    m_isActive = isActive;
}

sf::Vector2f Entity::getVelocity()
{
    return m_Velocity;
}

void Entity::setVelocity(sf::Vector2f newVelocity)
{
    m_Velocity = newVelocity;
}

void Entity::setTag(Tag newTag)
{
    m_Tag = newTag;
}

Tag Entity::getTag()
{
    return m_Tag;
}

Tag Entity::getCollider()
{
    return m_Collider;
}

void Entity::SetCollider(Tag newCollider)
{
    m_Collider = newCollider;
}

int Entity::getNumCollider()
{
    return m_NumCollider;
}

void Entity::setNumCollider(int num)
{
    m_NumCollider = num;
}
