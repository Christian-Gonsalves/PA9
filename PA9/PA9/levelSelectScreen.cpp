#include "LevelSelectScreen.hpp"
#include <iostream>

LevelSelectScreen::LevelSelectScreen(sf::Texture& playerTex, sf::Texture& lvlBgTex)
	: player(playerTex, { {205.f,140.f}, {370.f,430.f}, {780.f,710.f}, {1405.f,630.f}, {1650.f,80.f} }),
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
            startBattle = true;
    }
}

void LevelSelectScreen::draw(sf::RenderWindow& window)
{
    

	window.draw(bg);

    player.draw(window);
}

bool LevelSelectScreen::shouldStartBattle() const
{
    return startBattle;
}