#include "player.h"

void Player::Init(int n)
{
	currentAnimation = Animation(6, 1.0f / 100.0f);
	currentAnimation.setTexture(s);
	s.scale(Vector2f(10.f, 10.f));
	s.setPosition(Vector2f(150.0f, 170.0f));
}

void Player::Update()
{
	currentAnimation.Update();
	currentAnimation.setTexture(s);
}

void Player::Move(Vector2f vt_s, float deltaTime)
{
	velocity_s.y = 0.f;
	velocity_s.x = 0.f;
	if (s.getPosition().x < vt_s.x)
	{
		velocity_s.x = abs(vt_s.x - s.getPosition().x);
	}
	if (s.getPosition().x > vt_s.x)
	{
		velocity_s.x = -abs(s.getPosition().x - vt_s.x);
	}
	s.move(velocity_s * deltaTime);
}

void Player::Draw(RenderWindow& rd)
{
	rd.draw(s);
}
