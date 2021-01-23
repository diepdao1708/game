#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "PointBlock.h"
#include <vector>

class ListBlock
{
public:
	ListBlock();
	void Init();
	void Init1();
	void Init2();
	void Init3();
	void Init4();
	void Init5();
	void Init6();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	std::vector<PointBlock*> getBlockList();
	bool CheckBlock();
private:
	std::vector<PointBlock*> m_pointBlockList;
};