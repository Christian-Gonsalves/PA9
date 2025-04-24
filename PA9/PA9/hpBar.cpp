#include "hpBar.hpp"

hpBar::hpBar(float hw, float hh, float bw, float bh)
{
    bgBar.setSize(sf::Vector2f(bw, bh));
    bgBar.setFillColor(sf::Color::White);

    healthBar.setSize(sf::Vector2f(hw, hh));
    healthBar.setFillColor(sf::Color::Green);
}

void hpBar::setPosition(const sf::Vector2f& position)
{
    bgBar.setPosition(position);

    sf::Vector2f bgSize = bgBar.getSize();
    sf::Vector2f offset(
        (bgSize.x - healthBarMaxWidth) / 2.f,
        (bgSize.y - healthBarHeight) / 2.f
    );
    healthBar.setPosition(position + offset);
}

void hpBar::update(float curHP, float maxHP)
{
    float healthPercent = curHP / maxHP;
    sf::Vector2f size = bgBar.getSize();
    healthBar.setSize(sf::Vector2f(size.x * healthPercent, size.y));

    if (healthPercent > 0.5f)
    {
        healthBar.setFillColor(sf::Color::Green);
    }
    else if (healthPercent > 0.25f)
    {
        healthBar.setFillColor(sf::Color::Yellow);
    }
    else
    {
        healthBar.setFillColor(sf::Color::Red);
    }
}

void hpBar::draw(sf::RenderWindow& window)
{
    window.draw(bgBar);
    window.draw(healthBar);
}