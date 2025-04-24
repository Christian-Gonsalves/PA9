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
    TurnWrapper mainBattle(enemy, player);

    int playerMoveNum = -1, playerMoveTypeNum = -1; // Variables responsible for representing user input in move selection

    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) // Conditional taken from SFML website's event tutorial page
            {
                if (!battleScreen->isShowingMainDialogBox()) {
                    switch (keyPressed->scancode) {
                        case sf::Keyboard::Scancode::Z:
                            playerMoveNum = 0;
                            break;
                        case sf::Keyboard::Scancode::X:
                            playerMoveNum = 1;
                            break;
                        case sf::Keyboard::Scancode::C:
                            playerMoveNum = 2;
                            break;
                        case sf::Keyboard::Scancode::V:
                            playerMoveNum = 3;
                            break;
                        case sf::Keyboard::Scancode::Numpad1: case sf::Keyboard::Scancode::Num1:
                            playerMoveTypeNum = 0;
                            break;
                        case sf::Keyboard::Scancode::Numpad2: case sf::Keyboard::Scancode::Num2:
                            playerMoveTypeNum = 1;
                            break;
                        case sf::Keyboard::Scancode::Numpad3: case sf::Keyboard::Scancode::Num3:
                            playerMoveTypeNum = 2;
                            break;
                    }
                }
                    
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
        }
        else if (curScreen == battleScreen.get() && battleScreen->shouldExitBattle())
        {
            curScreen = levelScreen.get();
        }
    }
}