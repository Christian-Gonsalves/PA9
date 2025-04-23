#include "Player.hpp"

Player::Player(const sf::Texture& texture, const std::vector<sf::Vector2f>& pos)
    : positions(pos), curIndex(0), sprite(texture), inBattleSprite(texture)
{
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    sprite.setPosition(pos[curIndex]);

    inBattleSprite.setPosition(pos[0]);
}

void Player::moveRight()
{
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

void Player::drawInBattle(sf::RenderWindow& window)
{
    inBattleSprite.setScale(sf::Vector2f(1.f, 1.f));
    inBattleSprite.setPosition(sf::Vector2f(1300.f, 600.f));
    window.draw(inBattleSprite);
}

int Player::getCurrentIndex() const
{
    return curIndex;
}

