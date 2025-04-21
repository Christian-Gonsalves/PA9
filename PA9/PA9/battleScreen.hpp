#pragma once
#include "GameScreen.hpp"
#include "Andy.hpp"

class BattleScreen : public GameScreen
{
public:
    BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex);
    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

    bool shouldExitBattle() const;

private:
    sf::Texture& bgTex;
    sf::Sprite bg;
    bool exitBattle;
    sf::Texture andyTexture;
    Andy andy;
};