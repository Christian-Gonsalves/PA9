#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
public:
    // Overworld (level select) constructor
    Player(const sf::Texture& overworldTex, const std::vector<sf::Vector2f>& pos);

    // Battle constructor
    Player(const sf::Texture& battleTex);

    void moveLeft();
    void moveRight();
    void setPosition(int index);
    void draw(sf::RenderWindow& window);
    void drawInBattle(sf::RenderWindow& window);
    int getCurrentIndex() const;

private:
    sf::Sprite overworldSprite;
    sf::Sprite battleSprite;
    std::vector<sf::Vector2f> positions;
    int curIndex;
    bool inLevelSelect;
};