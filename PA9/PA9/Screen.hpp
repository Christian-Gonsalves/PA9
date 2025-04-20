#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Screen
{
public:
    Screen();
    bool loadAssets();
    void run(sf::RenderWindow& window);

private:
    sf::Texture bg1Texture;
    sf::Sprite bg1Sprite;
    sf::Texture playerTexture;
    sf::Sprite player;
    std::vector<sf::Vector2f> pos;
    int curIndex = 0;
    sf::Texture battleBgTexture;
    sf::Sprite battleBgSprite;

    bool inBattle = false;
};