#pragma once
#include <SFML/Graphics.hpp>
#pragma once
#include <SFML/Graphics.hpp>

class hpBar
{
public:
    hpBar(float w, float h);
    void setPosition(const sf::Vector2f& position);
    void update(float curHP, float maxHP);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape bgBar;
    sf::RectangleShape healthBar;
};