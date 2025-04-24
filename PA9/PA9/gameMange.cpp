#pragma once

#include "GameManage.hpp"
#include "turnWrapper.hpp"

GameManage::GameManage()
    : window(sf::VideoMode({ 1920, 1080 }), "SFML window")
{
    lvlBgTex.loadFromFile("assets/lvlSelectBackgroundPxl.png");
    playerTex.loadFromFile("assets/playerPxl.png");
    battleBgTex.loadFromFile("assets/inBattleBG.png");
    inBattlePlayerTex.loadFromFile("assets/playerInBattle.png");
    andyTex.loadFromFile("assets/andySprite.png");
    font = sf::Font("assets/dogicabold.ttf");
    levelScreen = std::make_unique<LevelSelectScreen>(playerTex, lvlBgTex);
    battleScreen = std::make_unique<BattleScreen>(battleBgTex, andyTex, inBattlePlayerTex, font);

    curScreen = levelScreen.get();
}
    

void GameManage::run()
{
    Character player;
    EnemyCharacter enemy;
    TurnWrapper mainBattle(enemy, player, battleScreen.get(), &window);

    int playerMoveNum = -1, playerMoveTypeNum = -1; // Variables responsible for representing user input in move selection

    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }


        // input, update, draw current screen
        curScreen->handleInput(window);
        curScreen->update();
        curScreen->draw(window);
        window.display();

        // check screen transitions
        if (curScreen == levelScreen.get() && levelScreen->shouldStartBattle())
        {
            curScreen = battleScreen.get();
            mainBattle.runBattle();

        }
        else if (curScreen == battleScreen.get() && battleScreen->shouldExitBattle())
        {
            curScreen = levelScreen.get();
        }
    }
}