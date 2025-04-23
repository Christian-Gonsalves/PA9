#pragma once
#include "GameScreen.hpp"
#include "Andy.hpp"
#include "Player.hpp"

class BattleScreen : public GameScreen
{
public:
    BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex, sf::Texture& playerTex, sf::Font& font, const std::vector<sf::Vector2f>& pos);
    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

    bool shouldExitBattle() const;

private:
    sf::Texture& bgTex;
    sf::Sprite bg;
    bool exitBattle, showDialog;
    sf::Texture andyTexture;
    Andy andy;
    Player player;
    sf::Font font;
    sf::Text dialog;
    sf::RectangleShape dialogBox;

};