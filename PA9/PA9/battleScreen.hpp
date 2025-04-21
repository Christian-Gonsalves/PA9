#pragma once
#include "GameScreen.hpp"

class BattleScreen : public GameScreen
{
public:
    BattleScreen(sf::Texture& bgTex);
    void handleInput(sf::RenderWindow& window) override;
    void update() override {}
    void draw(sf::RenderWindow& window) override;

    bool shouldExitBattle() const;

private:
    sf::Texture& bgTex;
    sf::Sprite bg;
    bool exitBattle = false;
};