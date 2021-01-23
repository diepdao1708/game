#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include<iostream>
using namespace std;
using namespace sf;
class Animation
{
private:
	vector<Texture> listTexture;
	float deltaTime;
	float currentFrame = 0;
public:
	Animation(){}
	Animation(int countImage, float deltaTime);
	void Update();
	void setTexture(Sprite& s);
	
};


