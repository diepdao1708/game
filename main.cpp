#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Animation.h"
#include "Ball.h"
using namespace std;
using namespace sf;
int main()
{
    float deltaTime = 1.0f / 60;
    Vector2f paddleSize(25, 100);
    RenderWindow window(sf::VideoMode(350, 600), "SFML works!");
    // Create the ball
    Ball ball(175.0f, 542.0f);
    ball.setBall();
    //------------



    /*sf::RectangleShape leftPaddle;
    leftPaddle.setSize(Vector2f(50.0f, 50.0f));
    leftPaddle.setOutlineThickness(3);
    leftPaddle.setOutlineColor(sf::Color::Black);
    leftPaddle.setFillColor(sf::Color::White);
    leftPaddle.setOrigin(paddleSize / 2.f);
    leftPaddle.setPosition(Vector2f(250.0f, 250.0f));*/



    //---- line 1
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

    //-------------------
    
    //------Animation
    Sprite s;
    s.scale(Vector2f(0.2f, 0.2f));
    s.setPosition(Vector2f(175.0f, 506.0f));
    Animation animation(9, 1.0f / 60.0f);
    animation.setTexture(s);
    //---------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonReleased)
            {
                cout << "Mouse Released\n";
            }
            if (event.type == Event::KeyReleased)
            {
                cout << "Key Released\n";
            }
            
        }
        
        // xu li logic
        // ball
        ball.upDate(window);
        ball.Input();
        //animation
        Vector2f vt_s;
        animation.Update();
        animation.setTexture(s);
        bool ok = ball.getOK();
        vt_s.x = ball.getPosition_x();
        vt_s.y = ball.getPosition_y();
        if (ok==0)
        {
            Vector2f velocity_s;
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
            s.move(velocity_s*deltaTime);
        }
        

        //-------------------
        window.clear(Color(153, 51, 102));
        ball.Draw(window);
        window.draw(s);
        //window.draw(leftPaddle);
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.display();
    }

    return 0;
}