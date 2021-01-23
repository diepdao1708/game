#include "MovingDirect.h"

MovingDirect::MovingDirect()
{
}

MovingDirect::~MovingDirect()
{
}

void MovingDirect::Update(sf::Vector2f pointB)
{
    float width = abs(pointB.x - m_PointA.x);
    float height = abs(pointB.y - m_PointA.y);
    float TanAngle = width / height;
    TanAngle = atan(TanAngle);
    m_Angle = 180.f / acos(1) * TanAngle;
    m_VectorUnit.x = abs(sin(TanAngle));
    m_VectorUnit.y = abs(cos(TanAngle));

    if (pointB.x < m_PointA.x)
    {
        m_Angle = -m_Angle;
        m_VectorUnit.x = -m_VectorUnit.x;
    }
    if (pointB.y > m_PointA.y)
    {
        if (pointB.x > m_PointA.x)
        {
            float delta = 90.f + 90.f - m_Angle;
            m_Angle = delta;
        }
        else
        {
            float delta = -180.f - m_Angle;
            m_Angle = delta;
        }
    }
    else m_VectorUnit.y = -m_VectorUnit.y;
}

void MovingDirect::Update(sf::Vector2f pointA, sf::Vector2f pointB)
{
    this->setPointA(pointA);
    Update(pointB);
}

sf::Vector2f MovingDirect::getVectorUnit()
{
    return m_VectorUnit;
}

float MovingDirect::getAngle()
{
    return m_Angle;
}

void MovingDirect::setPointA(sf::Vector2f pointA)
{
    m_PointA = pointA;
}
