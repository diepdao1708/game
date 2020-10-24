#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
using namespace std;
using namespace sf;
class BackGround
{
private:
public:
	BackGround() {}
	void InPut()
	{
        sf::Vertex line1[2] =
        {
            sf::Vertex(sf::Vector2f(0.f, 100.f)),
            sf::Vertex(sf::Vector2f(350.f, 100.f))
        };
        line1[0].color = sf::Color::White;
        line1[1].color = sf::Color::White;
        //---- line 2
        sf::Vertex line2[2] =
        {
            sf::Vertex(sf::Vector2f(0.f, 550.f)),
            sf::Vertex(sf::Vector2f(350.f, 550.f))
        };
        line2[0].color = sf::Color::White;
        line2[1].color = sf::Color::White;
	}
    virtual void Draw(RenderWindow& rd) {
        rd.draw(ball);
    }
};
