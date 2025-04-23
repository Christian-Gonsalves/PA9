#pragma once
#include "GameScreen.hpp"
#include "Andy.hpp"
#include "Player.hpp"

class BattleScreen : public GameScreen
{
public:
    BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex, sf::Texture& playerTex, sf::Font& font);
    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

    bool shouldExitBattle() const;

private:
    sf::Sprite bg;
    bool exitBattle, showDialog;
    Andy andy;
    Player player;
    sf::Text dialog;
    sf::RectangleShape dialogBox;
};
