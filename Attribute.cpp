#include "Attribute.h"

void Attribute::setHp(int hp)
{
    m_Hp = hp;
}

int Attribute::getHp()
{
    return m_Hp;
}

std::string Attribute::getStringHp()
{
    return std::to_string(m_Hp);
}

void Attribute::LoseHP(int offset)
{
    m_Hp -= offset;
}

void Attribute::Init()
{
}

void Attribute::Update(float detalTime)
{
}

void Attribute::Draw(sf::RenderWindow& window)
{
}
