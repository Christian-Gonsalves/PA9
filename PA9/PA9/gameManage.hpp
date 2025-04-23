#pragma once
#include <SFML/Graphics.hpp>
#include "LevelSelectScreen.hpp"
#include "BattleScreen.hpp"

class GameManage
{
public:
    GameManage();
    void run();

private:
    sf::RenderWindow window;
    sf::Texture playerTex, battleBgTex, lvlBgTex, andyTex, inBattlePlayerTex;
    std::vector<sf::Vector2f> positions;
    sf::Font font;
    std::unique_ptr<LevelSelectScreen> levelScreen;
    std::unique_ptr<BattleScreen> battleScreen;

    GameScreen* curScreen;
};