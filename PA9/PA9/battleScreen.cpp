#include "BattleScreen.hpp"

BattleScreen::BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex, sf::Font& font) : exitBattle(false), showDialog(true), bgTex(bgTex), bg(bgTex), andy(andyTex), andyTexture(andyTex), dialog(font)
{
    dialogBox.setSize(sf::Vector2f(350.f, 200.f));
    dialogBox.setFillColor(sf::Color::White);
    dialogBox.setPosition(sf::Vector2f(400.f, 300.f));
    dialog.setFont(font);
    dialog.setString("Andy: \n\nhello, world!");
    dialog.setCharacterSize(24);
    dialog.setFillColor(sf::Color::Black);
    dialog.setPosition(sf::Vector2f(420.f, 320.f));
}


void BattleScreen::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        exitBattle = true;
        sf::sleep(sf::milliseconds(200));
    }
    if (showDialog && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        showDialog = false;
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
    if (andy.hasEnteredBattle())
    {
        if (showDialog)
        {
            window.draw(dialogBox);
            window.draw(dialog);
        }
    }
}

bool BattleScreen::shouldExitBattle() const
{
    return exitBattle;
}