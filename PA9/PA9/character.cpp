#include "character.hpp"

Character::Character(int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int* newStatusEffects)
{
	attack = newAttack;
	maxHealth = newMaxHealth;
	currentHealth = newCurrentHealth;
	agility = newAgility;
	accuracy = newAccuracy;
	defense = newDefense;
	*statusEffects = *newStatusEffects;
}

Character::~Character()
{

}

void Character::setAttack(const int newAttack)
{
	attack = newAttack;
}

void Character::setMaxHealth(const int newMaxHealth)
{
	maxHealth = newMaxHealth;
}

void Character::setCurrentHealth(const int newCurHealth)
{
	currentHealth = newCurHealth;
}

void Character::setAgility(const int newAgility)
{
	agility = newAgility;
}

void Character::setAccuracy(const int newAccuracy)
{
	accuracy = newAccuracy;
}

void Character::setDefense(const int newDefense)
{
	defense = newDefense;
}

void Character::setStatusEffects(const int& newStatusEffect)
{
	*statusEffects = newStatusEffect;
}

void Character::setMoveSet(const Moves& newMoveSet)
{
	*MoveSet = newMoveSet;
}

int Character::getAttack(void) const
{
	return attack;
}

int Character::getMaxHealth(void) const
{
	return maxHealth;
}

int Character::getCurrentHealth(void) const
{
	return currentHealth;
}

int Character::getAgility(void) const
{
	return agility;
}

int Character::getAccuracy(void) const
{
	return accuracy;
}

int Character::getDefense(void) const
{
	return defense;
}

int& Character::getStatusEffect(void)
{
	return *this->statusEffects;
}

Moves& Character::getMoveSet(void)
{
	return *this->MoveSet;
}
