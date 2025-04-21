#pragma once
#include "GameScreen.hpp"
#include "Player.hpp"
class LevelSelectScreen : public GameScreen
{
public:
    LevelSelectScreen(sf::Texture& playerTex, sf::Texture& lvlBgTex);

    void handleInput(sf::RenderWindow& window) override;
    void update() override {}
    void draw(sf::RenderWindow& window) override;

    bool shouldStartBattle() const;

private:
    sf::Sprite bg;
    sf::Texture& bgTex;
    Player player;
    bool startBattle = false;
};