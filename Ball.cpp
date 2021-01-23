#include "Ball.h"

void Ball::Init()
{
    this->setPosition(sf::Vector2f(350, 880));
    m_Velocity = sf::Vector2f(0, 0);
    m_isFire = false;
    m_Speed = 500.f;
    this->setRadius(20);
    this->setOrigin(this->getRadius(), this->getRadius());
    texture.loadFromFile("ball.png");
    s.setTexture(texture);
    s.setOrigin(sf::Vector2f(texture.getSize().x*0.5f, texture.getSize().y*0.5f));
    s.setScale(sf::Vector2f(1.6, 1.6));
    setTag(Tag_Ball);
}

void Ball::Update(float deltatime)
{
    s.setPosition(this->getPosition());
    this->move(m_Velocity*deltatime);
}

void Ball::Draw(sf::RenderWindow& window)
{
    //window.draw(*this);
    window.draw(s);
}

void Ball::setIsFire(bool isFire)
{
    m_isFire = isFire;
}

bool Ball::isFire()
{
    return m_isFire;
}

void Ball::Fire()
{
    m_Velocity = m_VectorDirect * m_Speed;
    m_isFire = true;
}

void Ball::setDirect(sf::Vector2f unit)
{
    m_VectorDirect = unit;
}
