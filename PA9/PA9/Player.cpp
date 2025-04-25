#include "Player.hpp"

// Overworld constructor
Player::Player(const sf::Texture& overworldTex, const std::vector<sf::Vector2f>& pos)
	: positions(pos), curIndex(0), inLevelSelect(true), overworldSprite(overworldTex), battleSprite(overworldTex)
{
    //readFromFile("Player_Character.csv");

    overworldSprite.setTexture(overworldTex);
    overworldSprite.setScale(sf::Vector2f(0.8f, 0.8f));
    overworldSprite.setPosition(positions[curIndex]);

}

// Battle-only constructor
Player::Player(const sf::Texture& battleTex)
	: curIndex(0), inLevelSelect(false), battleSprite(battleTex), overworldSprite(battleTex),
    Character("", 0, 0, 0, 0, 0, 0, 0, nullptr, '\0')
{
    battleSprite.setTexture(battleTex);
    battleSprite.setScale(sf::Vector2f(1.f, 1.f));
    battleSprite.setPosition(sf::Vector2f(1300.f, 600.f));
}

void Player::moveRight()
{
    if (inLevelSelect && curIndex < positions.size() - 1)
        overworldSprite.setPosition(positions[++curIndex]);
}

void Player::moveLeft()
{
    if (inLevelSelect && curIndex > 0)
        overworldSprite.setPosition(positions[--curIndex]);
}

void Player::draw(sf::RenderWindow& window)
{
    if (inLevelSelect)
        window.draw(overworldSprite);
}

void Player::drawInBattle(sf::RenderWindow& window)
{
    window.draw(battleSprite);
}

int Player::getCurrentIndex() const
{
    return curIndex;
}