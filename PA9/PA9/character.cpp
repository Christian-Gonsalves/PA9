#include "character.hpp"

Character::Character(int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int* newStatusEffects)
{
	attack = newAttack;
	maxHealth = newMaxHealth;
	currentHealth = newCurrentHealth;
	agility = newAgility;
	accuracy = newAccuracy;
	defense = newDefense;
	statusEffects = newStatusEffects;
}

Character::~Character()
{

}
