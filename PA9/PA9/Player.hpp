#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
public:
    Player(const sf::Texture& texture, const std::vector<sf::Vector2f>& positions);

    void moveLeft();
    void moveRight();
    void setPosition(int index);
    void draw(sf::RenderWindow& window);
    int getCurrentIndex() const;

private:
    sf::Sprite sprite;
    std::vector<sf::Vector2f> positions;
    int curIndex;
};