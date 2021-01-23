#include "Animation.h"

Animation::Animation(int countImage, float deltaTime)
{
	for (int i = 1; i <= countImage; i++) 
	{
		Texture tmpImg;
		tmpImg.loadFromFile(to_string(i) + ".png");
		listTexture.push_back(tmpImg);
	}
	this->deltaTime = deltaTime;
}

void Animation::Update()
{
	currentFrame += deltaTime;
	if (currentFrame > listTexture.size() - 1) 
	{
		currentFrame = 0;
	}
}

void Animation::setTexture(Sprite& s)
{

	s.setTexture(listTexture[currentFrame]);
	s.setTextureRect(IntRect(0, 0, listTexture[currentFrame].getSize().x, listTexture[currentFrame].getSize().y));
	s.setOrigin((Vector2<float>)listTexture[currentFrame].getSize() * 0.5f);
}
