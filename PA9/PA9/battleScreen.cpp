#include "BattleScreen.hpp"

BattleScreen::BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex) : exitBattle(false), bgTex(bgTex), bg(bgTex), andy(andyTex), andyTexture(andyTex)
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

void BattleScreen::update()
{
	
	andy.update();
}

void BattleScreen::draw(sf::RenderWindow& window)
{
    window.draw(bg);
	andy.draw(window);
}

bool BattleScreen::shouldExitBattle() const
{
    return exitBattle;
}