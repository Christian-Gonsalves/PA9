#include "Player.hpp"

Player::Player(const sf::Texture& texture, const std::vector<sf::Vector2f>& pos)
	: positions(pos), curIndex(0), sprite(texture)
{
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    sprite.setPosition(pos[curIndex]);
}

void Player::moveRight() {
    if (curIndex < positions.size() - 1)
    {
        curIndex++;
        sprite.setPosition(positions[curIndex]);
    }
}

void Player::moveLeft()
{
    if (curIndex > 0)
    {
        curIndex--;
        sprite.setPosition(positions[curIndex]);
    }
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

int Player::getCurrentIndex() const
{
    return curIndex;
}