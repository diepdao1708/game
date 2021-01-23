#pragma once
#include "Ball.h"
#include "PointBlock.h"
#include <vector>
#include "CollisionManager.h"
#include "MovingDirect.h"

class Character
{
public:
	Character();
	void Init();
	void Init1();
	void Init2();
	void Init3();
	void Init4();
	void Init5();
	void Init6();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Fire(sf::Vector2f dir);
	std::vector<Ball*> getBallList();
	void AfterCollisionWithABlock(PointBlock &block);
	bool checkBall();
private:
	std::vector<Ball*> m_BallList;
	MovingDirect m_DirectBall;
	bool m_isFire;
	float m_CurrentTime;
	float m_TimeFire;
};