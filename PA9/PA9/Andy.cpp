#include "Andy.hpp"

Andy::Andy(const sf::Texture& texture)
	: targetX(700.f), speed(1.5f), enteredBattle(false), andySprite(texture),
	EnemyCharacter("", "", 0, 0, 0, 0, 0, 0, 0, nullptr, '\0')
{
	readFromFile("Andy_Character.csv");
	andySprite.setPosition(sf::Vector2f(-300.f, 400.f ));
	andySprite.setScale(sf::Vector2f(0.25f, 0.25f ));
}

void Andy::update()
{
    if (!enteredBattle)
    {
        andySprite.move(sf::Vector2f(speed, 0.f));
        if (andySprite.getPosition().x >= targetX)
        {
            andySprite.setPosition(sf::Vector2f(targetX, andySprite.getPosition().y));
            enteredBattle = true;
        }
    }
}

void Andy::draw(sf::RenderWindow& window)
{
	window.draw(andySprite);
}

bool Andy::hasEnteredBattle() const
{
	return enteredBattle;
}