#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "PointBlock.h"
#include "CollisionManager.h"
#include "Character.h"
#include "ListBlock.h"
#include "player.h"
#include "Animation.h"
#include "Ground.h"
#include "NextLevel.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(700, 900), "ONE MORE BRICK 2!");
    Ground ground;
    ground.Init();
    NextLevel nextlevel;

    Character character;
    character.Init();
    ListBlock listBlock;
    listBlock.Init();
    CollisionManager collisionManager;
    for (auto it : listBlock.getBlockList())
    {
        collisionManager.Push(*it);
    }
    for (auto it : character.getBallList())
    {
        collisionManager.Push(*it);
    }

    Character character1;
    character1.Init1();
    ListBlock listBlock1;
    listBlock1.Init1();
    CollisionManager collisionManager1;
    for (auto it : listBlock1.getBlockList())
    {
        collisionManager1.Push(*it);
    }
    for (auto it : character1.getBallList())
    {
        collisionManager1.Push(*it);
    }

    Character character2;
    character2.Init2();
    ListBlock listBlock2;
    listBlock2.Init2();
    CollisionManager collisionManager2;
    for (auto it : listBlock2.getBlockList())
    {
        collisionManager2.Push(*it);
    }
    for (auto it : character2.getBallList())
    {
        collisionManager2.Push(*it);
    }

    Character character3;
    character3.Init3();
    ListBlock listBlock3;
    listBlock3.Init3();
    CollisionManager collisionManager3;
    for (auto it : listBlock3.getBlockList())
    {
        collisionManager3.Push(*it);
    }
    for (auto it : character3.getBallList())
    {
        collisionManager3.Push(*it);
    }

    Character character4;
    character4.Init4();
    ListBlock listBlock4;
    listBlock4.Init4();
    CollisionManager collisionManager4;
    for (auto it : listBlock4.getBlockList())
    {
        collisionManager4.Push(*it);
    }
    for (auto it : character4.getBallList())
    {
        collisionManager4.Push(*it);
    }

    Character character5;
    character5.Init5();
    ListBlock listBlock5;
    listBlock5.Init5();
    CollisionManager collisionManager5;
    for (auto it : listBlock5.getBlockList())
    {
        collisionManager5.Push(*it);
    }
    for (auto it : character5.getBallList())
    {
        collisionManager5.Push(*it);
    }

    Character character6;
    character6.Init6();
    ListBlock listBlock6;
    listBlock6.Init6();
    CollisionManager collisionManager6;
    for (auto it : listBlock6.getBlockList())
    {
        collisionManager6.Push(*it);
    }
    for (auto it : character6.getBallList())
    {
        collisionManager6.Push(*it);
    }

    bool stargame = false;
    bool level1 = false;
    bool level2 = false;
    bool level3 = false;
    bool level4 = false;
    bool level5 = false;
    bool level6 = false;
    bool level7 = false;
    bool nextLevel1 = false;
    bool nextLevel2 = false;
    bool nextLevel3 = false;
    bool nextLevel4 = false;
    bool nextLevel5 = false;
    bool nextLevel6 = false;
    bool nextLevel7 = false;
    
    int n = 1;
    sf::Clock clock;
    float deltaTime = 0.0f;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
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
        window.clear();
        
        if (stargame == 0 && Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            stargame = 1;
        }
        
        if (stargame == 0)
        {
            ground.Update(deltaTime);
            ground.Draw(window);
        }
        else
        {
            ground.DrawPlay(window);
            if (n == 1)
            {
                if (nextLevel1 == false)
                {
                    nextlevel.DrawLevel1(window);
                }
                if (level1 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level1 = true;
                    nextLevel1 = true;
                }
                
                if (level1 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    
                    listBlock.Update(deltaTime);
                    character.Update(deltaTime);
                    for (auto it : listBlock.getBlockList())
                    {
                        character.AfterCollisionWithABlock(*it);
                    }

                    collisionManager.Update(deltaTime);

                    if (listBlock.CheckBlock() == true && character.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock.CheckBlock() == false)
                    {
                        n = 0;
                    } 
                    if (listBlock.CheckBlock() == false && character.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock.Draw(window);
                    character.Draw(window);
                }
            }
            
            if (n == 2)
            {
                if (nextLevel2 == false)
                {
                    nextlevel.DrawLevel2(window);
                }
                if (level2 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level2 = true;
                    nextLevel2 = true;
                }
                if (level2 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character1.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    listBlock1.Update(deltaTime);
                    character1.Update(deltaTime);
                    for (auto it : listBlock1.getBlockList())
                    {
                        character1.AfterCollisionWithABlock(*it);
                    }

                    collisionManager1.Update(deltaTime);
                    if (listBlock1.CheckBlock() == true && character1.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock1.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock1.CheckBlock() == false)
                    {
                        n = 0;
                    }
                    if (listBlock1.CheckBlock() == false && character1.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock1.Draw(window);
                    character1.Draw(window);
                }
            }

            if (n == 3)
            {
                if (nextLevel3 == false)
                {
                    nextlevel.DrawLevel3(window);
                }
                if (level3 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level3 = true;
                    nextLevel3 = true;
                }
                if (level3 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character2.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    listBlock2.Update(deltaTime);
                    character2.Update(deltaTime);
                    for (auto it : listBlock2.getBlockList())
                    {
                        character2.AfterCollisionWithABlock(*it);
                    }

                    collisionManager2.Update(deltaTime);
                    if (listBlock2.CheckBlock() == true && character2.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock2.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock2.CheckBlock() == false)
                    {
                        n = 0;
                    }
                    if (listBlock2.CheckBlock() == false && character2.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock2.Draw(window);
                    character2.Draw(window);
                }
            }

            if (n == 4)
            {
                if (nextLevel4 == false)
                {
                    nextlevel.DrawLevel4(window);
                }
                if (level4 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level4 = true;
                    nextLevel4 = true;
                }
                if (level4 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character3.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    listBlock3.Update(deltaTime);
                    character3.Update(deltaTime);
                    for (auto it : listBlock3.getBlockList())
                    {
                        character3.AfterCollisionWithABlock(*it);
                    }

                    collisionManager3.Update(deltaTime);
                    if (listBlock3.CheckBlock() == true && character3.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock3.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock3.CheckBlock() == false)
                    {
                        n = 0;
                    }
                    if (listBlock3.CheckBlock() == false && character3.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock3.Draw(window);
                    character3.Draw(window);
                }
            }

            if (n == 5)
            {
                if (nextLevel5 == false)
                {
                    nextlevel.DrawLevel5(window);
                }
                if (level5 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level5 = true;
                    nextLevel5 = true;
                }
                if (level5 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character4.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    listBlock4.Update(deltaTime);
                    character4.Update(deltaTime);
                    for (auto it : listBlock4.getBlockList())
                    {
                        character4.AfterCollisionWithABlock(*it);
                    }

                    collisionManager4.Update(deltaTime);
                    if (listBlock4.CheckBlock() == true && character4.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock4.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock4.CheckBlock() == false)
                    {
                        n = 0;
                    }
                    if (listBlock4.CheckBlock() == false && character4.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock4.Draw(window);
                    character4.Draw(window);
                }
            }

            if (n == 6)
            {
                if (nextLevel6 == false)
                {
                    nextlevel.DrawLevel6(window);
                }
                if (level6 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level6 = true;
                    nextLevel6 = true;
                }
                if (level6 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character5.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    listBlock5.Update(deltaTime);
                    character5.Update(deltaTime);
                    for (auto it : listBlock5.getBlockList())
                    {
                        character5.AfterCollisionWithABlock(*it);
                    }

                    collisionManager5.Update(deltaTime);
                    if (listBlock5.CheckBlock() == true && character5.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock5.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock5.CheckBlock() == false)
                    {
                        n = 0;
                    }
                    if (listBlock5.CheckBlock() == false && character5.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock5.Draw(window);
                    character5.Draw(window);
                }
            }

            if (n == 7)
            {
                if (nextLevel7 == false)
                {
                    nextlevel.DrawLevel7(window);
                }
                if (level7 == false && Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    level7 = true;
                    nextLevel7 = true;
                }
                if (level7 == true)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        character6.Fire((sf::Vector2f)sf::Mouse::getPosition(window));
                    }
                    listBlock6.Update(deltaTime);
                    character6.Update(deltaTime);
                    for (auto it : listBlock6.getBlockList())
                    {
                        character6.AfterCollisionWithABlock(*it);
                    }

                    collisionManager6.Update(deltaTime);
                    if (listBlock6.CheckBlock() == true && character6.checkBall() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock6.CheckBlock() == true)
                    {
                        n++;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::A) && listBlock6.CheckBlock() == false)
                    {
                        n = 0;
                    }
                    if (listBlock6.CheckBlock() == false && character6.checkBall() == true)
                    {
                        n = 0;
                    }
                    listBlock6.Draw(window);
                    character6.Draw(window);
                }
            }

            if (n == 0)
            {
                nextlevel.DrawLose(window);
                if (Keyboard::isKeyPressed(Keyboard::Key::Space))
                {
                    return 0;
                }
            }

            if (n == 8)
            {
                nextlevel.DrawWin(window);
                if (Keyboard::isKeyPressed(Keyboard::Key::Space))
                {
                    return 0;
                }
            }
        }
        window.display();
    }
    return 0;
}