#include "LevelSelectScreen.hpp"
#include <iostream>

LevelSelectScreen::LevelSelectScreen(sf::Texture& playerTex, sf::Texture& lvlBgTex)
	: startBattle(false), isFlashing(false), flashCount(0), player(playerTex, { {205.f,140.f}, {370.f,430.f}, {780.f,710.f}, {1405.f,630.f}, {1650.f,80.f} }),
    bgTex(lvlBgTex), bg(lvlBgTex)
{
    
}

void LevelSelectScreen::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        player.moveRight();
        sf::sleep(sf::milliseconds(200));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        player.moveLeft();
        sf::sleep(sf::milliseconds(200));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        if (player.getCurrentIndex() == 4)
        {
            isFlashing = true;
            flashCount = 0;
            flashTimer.restart();
        }
    }
}

void LevelSelectScreen::draw(sf::RenderWindow& window)
{
	if (isFlashing) //creating a flash effect before the battle starts
    {
        if (flashTimer.getElapsedTime().asMilliseconds() >= 100) //time between flashes
        {
            flashCount++;
            flashTimer.restart();
        }
        if (flashCount % 2 == 0)// switch between black screen and level screen
        {
            sf::RectangleShape flash(sf::Vector2f(window.getSize())); // blackscreen
            flash.setFillColor(sf::Color::Black);
            window.draw(flash);
        }
        else
        {
            window.draw(bg);
            player.draw(window);
        }
        if (flashCount >= 6)// end flash after a few times
        {
            isFlashing = false;
            startBattle = true;
        }
    }
    else
    {
        window.draw(bg);
        player.draw(window);
    }
}

bool LevelSelectScreen::shouldStartBattle() 
{
    if (startBattle) {
        startBattle = false;
        return true;
    }
    else {
        return false;
    }
}