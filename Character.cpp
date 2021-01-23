#include "Character.h"

Character::Character()
{
	m_CurrentTime = 0.f;
	m_isFire = false;
	m_TimeFire = 0.1f;
}

void Character::Init()
{
	for (int i = 0; i < 30; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Init1()
{
	for (int i = 0; i < 50; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Init2()
{
	for (int i = 0; i < 100; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Init3()
{
	for (int i = 0; i < 50; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Init4()
{
	for (int i = 0; i < 120; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Init5()
{
	for (int i = 0; i < 100; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Init6()
{
	for (int i = 0; i < 120; i++)
	{
		Ball* tmp = new Ball();
		tmp->Init();
		m_BallList.push_back(tmp);
	}
}

void Character::Update(float deltaTime)
{
	
	if (m_isFire == true)
	{
		m_CurrentTime += deltaTime;
		if (m_CurrentTime >= m_TimeFire)
		{
			m_isFire = false;
			m_CurrentTime = 0.f;
		}
	}
	for (auto it : m_BallList)
	{
		it->Update(deltaTime);
	}
}

void Character::Draw(sf::RenderWindow& window)
{
	for (auto it : m_BallList)
	{
		it->Draw(window);
	}
}

void Character::Fire(sf::Vector2f dir)
{
	if (m_isFire == true) return;
	Ball* ball=nullptr;
	for (auto it : getBallList())
	{
		if (it->isFire() == false)
		{
			ball = it;
			ball->setIsFire(true);
			break;
		}
	}
	if (ball == nullptr)
	{
		return;
	}
	m_DirectBall.setPointA(ball->getPosition());
	m_DirectBall.Update(dir);
	ball->setDirect(m_DirectBall.getVectorUnit());
	ball->Fire();
	m_isFire = true;
}

std::vector<Ball*> Character::getBallList()
{
	return m_BallList;
}

void Character::AfterCollisionWithABlock(PointBlock& block)
{
	
	for (auto it : getBallList())
	{	
		if (it->isFire()) it->setVelocity(CollisionManager::getVelocity(*it, block, it->getVelocity()));
	}
}

bool Character::checkBall()
{
	for (auto it : m_BallList)
	{
		if (it->isFire() == false || it->getVelocity() != Vector2f(0, 0)) return false;
	}
	return true;
}
