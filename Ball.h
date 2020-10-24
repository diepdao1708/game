#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;
using namespace sf;
class Ball
{
private:
	CircleShape ball;
	float x, y;
	Vector2i velocity;
	Vector2f vt_end;
	float deltaTime;
	Vector2i vt;
	int ok = 2;
public:
	Ball(){}
	Ball(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	void setBall()
	{
		ball.setPosition(Vector2f(x, y));
		ball.setRadius(10.0f - 3);
		ball.setOutlineThickness(3);
		ball.setFillColor(sf::Color::White);
		ball.setOrigin(10.0f , 10.0f );
	}
	virtual void Draw(RenderWindow& rd) {
		rd.draw(ball);
	}
	void upDate(RenderWindow& rd)
	{
		vt.x = Mouse::getPosition(rd).x;
		vt.y = Mouse::getPosition(rd).y;
	}
	
	void Input()
	{
		
		if (Keyboard::isKeyPressed(Keyboard::Space)) deltaTime = 1.0f/400.f;
		else deltaTime = 1.0f/800.f;
		if(Mouse::isButtonPressed(Mouse::Left))
		{
			velocity.x = vt.x - x;
			velocity.y = -abs(y - vt.y);
			ok = 1;
		}
		if (ok)
		{
			if (ball.getPosition().x < 5) {
				velocity.x = abs(velocity.x);
			}
			if (ball.getPosition().x > 345) {
				velocity.x = -abs(velocity.x);
			}
			if (ball.getPosition().y < 110) {
				velocity.y = abs(velocity.y);
			}
			if (ball.getPosition().y > 542) 
			{
				ok = 0;
				velocity.x = 0;
				velocity.y = 0;
				vt_end.x = ball.getPosition().x;
				vt_end.y = ball.getPosition().y;
			}
			ball.move((Vector2f)(velocity)*deltaTime);
		}
	}
	bool getOK()
	{
		return this->ok;
	}
	float getPosition_x()
	{
		return this->vt_end.x;
	}
	float getPosition_y()
	{
		return this->vt_end.y;
	}


};

