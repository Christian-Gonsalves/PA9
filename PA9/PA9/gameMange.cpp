#pragma once

#include "GameManage.hpp"
#include "turnWrapper.hpp"
#include <Windows.h>
#include <SFML/Audio.hpp>

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

    this->buffer = new sf::SoundBuffer[3]{ sf::SoundBuffer("assets/Audio/sound1.wav"), sf::SoundBuffer("assets/Audio/sound2.wav"), sf::SoundBuffer("assets/Audio/sound5.ogg") };
    this->sound = new sf::Sound[3]{ sf::Sound(buffer[0]), sf::Sound(buffer[1]), sf::Sound(buffer[2]) };

    curScreen = levelScreen.get();
}
    

void GameManage::run()
{
    Character player;
    EnemyCharacter enemy;
    bool winState;

    Menu menu(this->window.getSize().x, this->window.getSize().y);
    menu.load_menu(this->window);
    sound[0].play();

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
                for (int i = 0; i < 2; i++)
                {
                    sound[i].stop(); 
                }
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
            
            sound[2].play();
            if (sound[0].getStatus() == sf::Sound::Status::Playing)
            {
                sound[0].stop();
            }
            sound[1].setLooping(true);
            sound[1].play();


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

                
                if (sound[1].getStatus() == sf::Sound::Status::Playing)
                {
                    sound[1].stop();
                }
                sound[0].setLooping(true);
                sound[0].play();
                window.close();
            }
        }
    }
}
