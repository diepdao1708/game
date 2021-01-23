#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
class Ground
{
private:
	Sprite s, s1, s2, backgroundplay;
	Texture texture, texture1, texture2, texturePlay;
	Player player;
public:
	void Init();
	void Update(float deltaTime);
	void Draw(RenderWindow& rd);
	void DrawPlay(RenderWindow& rd);
};
