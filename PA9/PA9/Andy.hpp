#pragma once
#include "enemyCharacter.hpp"
#include <SFML/Graphics.hpp>
class Andy/*: public EnemyCharacter*/
{
public:
	Andy(const sf::Texture& texture);
	void update();
	void draw(sf::RenderWindow& window);
	bool hasEnteredBattle() const;
private:
	sf::Sprite andySprite;
	float targetX;
	float speed;
	bool enteredBattle;

};