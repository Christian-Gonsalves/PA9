#include "BattleScreen.hpp"

BattleScreen::BattleScreen(sf::Texture& bgTex) : bgTex(bgTex), bg(bgTex)
{
    
}

void BattleScreen::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        exitBattle = true;
        sf::sleep(sf::milliseconds(200));
    }
}

void BattleScreen::draw(sf::RenderWindow& window)
{
    window.draw(bg);
}

bool BattleScreen::shouldExitBattle() const
{
    return exitBattle;
}