#include "GameManage.hpp"
#include "Menu.hpp"
GameManage::GameManage()

    : window(sf::VideoMode({ 1920, 1080 }), "SFML window")
{
    lvlBgTex.loadFromFile("assets/lvlSelectBackgroundPxl.png");
    playerTex.loadFromFile("assets/playerPxl.png");
    battleBgTex.loadFromFile("assets/inBattleBG.png");
    andyTex.loadFromFile("assets/andySprite.png");
    levelScreen = std::make_unique<LevelSelectScreen>(playerTex, lvlBgTex);
    battleScreen = std::make_unique<BattleScreen>(battleBgTex, andyTex);

    curScreen = levelScreen.get();
    this->buffer = new sf::SoundBuffer[3]{ sf::SoundBuffer("Audio/sound1.wav"), sf::SoundBuffer("Audio/sound2.wav"), sf::SoundBuffer("Audio/sound5.ogg") };
    this->sound = new sf::Sound[3]{ sf::Sound(buffer[0]), sf::Sound(buffer[1]), sf::Sound(buffer[2]) };


}



void GameManage::run()
{
    Menu menu(this->window.getSize().x, this->window.getSize().y);
    menu.load_menu(this->window);
    sound[0].play();
    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        // input, update, draw current screen
        curScreen->handleInput(window);
        curScreen->update();
        curScreen->draw(window);
        window.display();

        // check screen transitions
        if (curScreen == levelScreen.get() && levelScreen->shouldStartBattle())
        {
            if (sound[0].getStatus() == sf::Sound::Status::Playing)
            {
                sound[0].stop();
            }
            sound[1].setLooping(true);
            sound[1].play();

            curScreen = battleScreen.get();
        }
        else if (curScreen == battleScreen.get() && battleScreen->shouldExitBattle())
        {
            sound[2].play();
            if (sound[1].getStatus() == sf::Sound::Status::Playing)
            {
                sound[1].stop();
            }
            sound[0].setLooping(true);
            sound[0].play();
            curScreen = levelScreen.get();
        }
    }
}
