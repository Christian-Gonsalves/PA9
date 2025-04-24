<<<<<<< HEAD
#include "Screen.hpp"
#include <SFML/Window/Event.hpp>

Screen::Screen()
    : bg1Texture("assets/lvlSelectBackgroundPxl.png"),
    bg1Sprite(bg1Texture)
{
    player.setRadius(30);
    player.setFillColor(sf::Color::Magenta);


    pos = {
        {210.f, 193.f},
        {372.f, 478.f},
        {782.f, 750.f},
        {1405.f, 675.f},
        {1650.f, 120.f}
    };
    player.setPosition(pos[curIndex]);
}

bool Screen::loadAssets()
{
    bg1Texture = sf::Texture("assets/lvlSelectBackgroundPxl.png");

    bg1Sprite = sf::Sprite(bg1Texture);
    return true;
}

void Screen::run(sf::RenderWindow& window)
{
    //sf::Event event;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            if (curIndex < static_cast<int>(pos.size()) - 1)
            {
                curIndex++;
                player.setPosition(pos[curIndex]);
                sf::sleep(sf::milliseconds(150));
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            if (curIndex > 0)
            {
                curIndex--;
                player.setPosition(pos[curIndex]);
                sf::sleep(sf::milliseconds(150));
            }
        }

        window.clear();
        window.draw(bg1Sprite);
        window.draw(player);
        window.display();
    }
}
=======
//#include "Screen.hpp"
//#include <SFML/Window/Event.hpp>
//
//Screen::Screen(): curIndex(0), bg1Texture("assets/lvlSelectBackgroundPxl.png"), bg1Sprite(bg1Texture),
//playerTexture("assets/playerPxl.png"), player(playerTexture), battleBgTexture("assets/inBattleBG.png"),
//battleBgSprite(battleBgTexture)
//{
//    player.setScale(sf::Vector2f(0.8f, 0.8f));
//    pos = {
//        {205.f, 140.f},
//        {370.f, 430.f},
//        {780.f, 710.f},
//        {1405.f, 630.f},
//        {1650.f, 80.f}
//    };
//    player.setPosition(pos[curIndex]);
//}
//
//bool Screen::loadAssets()
//{
//    if (!bg1Texture.loadFromFile("assets/lvlSelectBackgroundPxl.png"))
//        return false;
//
//    bg1Sprite.setTexture(bg1Texture);
//    return true;
//}
//
//void Screen::run(sf::RenderWindow& window)
//{
//    //sf::Event event;
//    while (window.isOpen())
//    {
//        while (const std::optional event = window.pollEvent())
//        {
//            if (event->is<sf::Event::Closed>())
//                window.close();
//        }
//
//        if (!inBattle)
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//            {
//                if (curIndex < static_cast<int>(pos.size()) - 1)
//                {
//                    curIndex++;
//                    player.setPosition(pos[curIndex]);
//                    sf::sleep(sf::milliseconds(200));
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//            {
//                if (curIndex > 0)
//                {
//                    curIndex--;
//                    player.setPosition(pos[curIndex]);
//                    sf::sleep(sf::milliseconds(200));
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
//            {
//                // Enter battle
//                inBattle = true;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        else
//        {
//            // Battle input
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
//                // Return to map
//                inBattle = false;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        window.clear();
//
//        if (!inBattle)
//        {
//            window.draw(bg1Sprite);
//            window.draw(player);
//        }
//        else
//        {
//            window.draw(battleBgSprite);
//            
//        }
//        window.display();
//    }
//}
>>>>>>> andres-2
