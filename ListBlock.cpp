#include "ListBlock.h"

ListBlock::ListBlock()
{
}

void ListBlock::Init()
{
	PointBlock* tmp = new PointBlock();
	tmp->Init(350, 50);
	m_pointBlockList.push_back(tmp);
}

void ListBlock::Init1()
{
	float kc = 150.0f;
	for (int i = 0; i < 5; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc, 150);
		m_pointBlockList.push_back(tmp);
		kc += 100.0f;
	}
}

void ListBlock::Init2()
{
	float kc = 150.0f;
	for (int i = 0; i < 5; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(250, kc);
		m_pointBlockList.push_back(tmp);
		kc += 100.0f;
	}
	float kc1 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc1, 150);
		m_pointBlockList.push_back(tmp);
		kc1 += 100.0f;
	}
	float kc2 = 250.0f;
	for (int i = 0; i < 3; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(450, kc2);
		m_pointBlockList.push_back(tmp);
		kc2 += 100.0f;
	}
	float kc3 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc3, 550);
		m_pointBlockList.push_back(tmp);
		kc3 += 100.0f;
	}
}

void ListBlock::Init3()
{

	float kc = 150.0f;
	for (int i = 0; i < 5; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(350, kc);
		m_pointBlockList.push_back(tmp);
		kc += 100.0f;
	}
}

void ListBlock::Init4()
{

	float kc = 150.0f;
	for (int i = 0; i < 5; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(250, kc);
		m_pointBlockList.push_back(tmp);
		kc += 100.0f;
	}
	float kc1 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc1, 150);
		m_pointBlockList.push_back(tmp);
		kc1 += 100.0f;
	}
	float kc2 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc2, 350);
		m_pointBlockList.push_back(tmp);
		kc2 += 100.0f;
	}
	float kc3 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc3, 550);
		m_pointBlockList.push_back(tmp);
		kc3 += 100.0f;
	}
	
}

void ListBlock::Init5()
{
	float kc = 150.0f;
	for (int i = 0; i < 5; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(250, kc);
		m_pointBlockList.push_back(tmp);
		kc += 100.0f;
	}
	float kc1 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc1, 150);
		m_pointBlockList.push_back(tmp);
		kc1 += 100.0f;
	}
	float kc2 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc2, 350);
		m_pointBlockList.push_back(tmp);
		kc2 += 100.0f;
	}
	PointBlock* tmp = new PointBlock();
	tmp->Init(450, 250);
	m_pointBlockList.push_back(tmp);
}

void ListBlock::Init6()
{
	float kc = 150.0f;
	for (int i = 0; i < 5; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc, 150);
		m_pointBlockList.push_back(tmp);
		kc += 100.0f;
	}
	float kc1 = 250.0f;
	for (int i = 0; i < 4; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(150, kc1);
		m_pointBlockList.push_back(tmp);
		kc1 += 100.0f;
	}
	float kc2 = 250.0f;
	for (int i = 0; i < 6; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(550, kc2);
		m_pointBlockList.push_back(tmp);
		kc2 += 100.0f;
	}
	float kc3 = 250.0f;
	for (int i = 0; i < 3; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc3, 750);
		m_pointBlockList.push_back(tmp);
		kc3 += 100.0f;
	}
	float kc4 = 250.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc4, 550);
		m_pointBlockList.push_back(tmp);
		kc4 += 100.0f;
	}
	float kc5 = 350.0f;
	for (int i = 0; i < 2; i++)
	{
		PointBlock* tmp = new PointBlock();
		tmp->Init(kc5, 350);
		m_pointBlockList.push_back(tmp);
		kc5 += 100.0f;
	}
}

void ListBlock::Update(float deltaTime)
{
	for (auto it : m_pointBlockList)
	{
		it->Update(deltaTime);
	}
}

void ListBlock::Draw(sf::RenderWindow& window)
{
	for (auto it : m_pointBlockList)
	{
		it->Draw(window);
	}
}

std::vector<PointBlock*> ListBlock::getBlockList()
{
	return m_pointBlockList;
}

bool ListBlock::CheckBlock()
{
	for (auto it : m_pointBlockList)
	{
		if (it->isActive() == true) return false;
	}
	return true;
}
