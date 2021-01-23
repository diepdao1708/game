#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include<iostream>
#include<cmath>
#include "Animation.h"
using namespace std;
using namespace sf;
class Player 
{
private:
	Sprite s;
	Animation currentAnimation;
	Vector2f velocity_s;
public:
	Player(){}
	void Init(int n);
	
	void Update();
	
	void Move(Vector2f vt_s, float deltaTime);
	void Draw(RenderWindow& rd);
	
};

