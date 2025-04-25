#pragma once
#include "GameScreen.hpp"
#include "Andy.hpp"
#include "Player.hpp"
#include "hpBar.hpp"
#include "textBox.hpp"
#include <iostream>

class BattleScreen : public GameScreen
{
public:
    BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex, sf::Texture& playerTex, sf::Font& font);
    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

    bool shouldExitBattle();
    bool hasAnimationConcluded() const { return andy.hasEnteredBattle(); }

    bool isShowingMainDialogBox() const { return showDialog; } // if it isn't, it's player choice time
    void setShowingMainDialogueBox(bool newState) { showDialog = newState; }

    textBox* getDialogueBox() { return &dialogBox; }
    textBox* getMove1Box() { return &move1; }
    textBox* getMove2Box() { return &move2; }
    textBox* getMove3Box() { return &move3; }
    textBox* getMove4Box() { return &move4; }

    int getSelectedTypeIndex() const { return selectedTypeIndex; }
    int getSelectedMoveIndex() const { return selectedMoveIndex; }


private:
    sf::Sprite bg;
    bool exitBattle, showDialog;
    Andy andy;
    Player player;
    hpBar pHealthBar, eHealthBar;

    textBox defBox, strBox, agilBox;
    textBox move1, move2, move3, move4;
    textBox dialogBox;

    int selectedTypeIndex;
    int selectedMoveIndex;
    enum class MenuState { SelectingType, SelectingMove };
    MenuState menuState;
    bool dialogInit;

};
