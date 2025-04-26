#pragma once

#include "GameManage.hpp"
#include "turnWrapper.hpp"
#include <Windows.h>

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
    bool winState;

    player.readFromFile("Player_Character.csv");
    enemy.readFromFile("Andy_Character.csv");

    player.sortMoves();

    TurnWrapper mainBattle(enemy, player, battleScreen.get(), &window);

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
        if (levelScreen->shouldStartBattle()) {

            // Beginning battle Animation
            while (!battleScreen->hasAnimationConcluded()) {
                window.clear();
                battleScreen->handleInput(window);
                battleScreen->update();
                battleScreen->draw(window);
                window.display();
            }

            winState = mainBattle.runBattle();
            
            // Temporary mesure. Should set up some way of deciding what player & enemy should be besides the defaultssss
            mainBattle.setPlayer(player);
            mainBattle.setEnemy(enemy);

            if (winState) {
                window.close();
            }
        }
    }
}