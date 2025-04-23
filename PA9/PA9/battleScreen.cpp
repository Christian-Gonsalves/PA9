#include "BattleScreen.hpp"

BattleScreen::BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex, sf::Texture& playerTex, sf::Font& font)
    : bg(bgTex), exitBattle(false), showDialog(true), andy(andyTex), player(playerTex), dialog(font)
{
    // Set up dialog box
    dialogBox.setSize(sf::Vector2f(350.f, 200.f));
    dialogBox.setFillColor(sf::Color::White);
    dialogBox.setPosition(sf::Vector2f(400.f, 300.f));

    // Set up dialog text
    dialog.setString("Andy:\n\nHello, world!");
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
    player.drawInBattle(window);

    if (andy.hasEnteredBattle() && showDialog)
    {
        window.draw(dialogBox);
        window.draw(dialog);
    }
}

bool BattleScreen::shouldExitBattle() const
{
    return exitBattle;
}
