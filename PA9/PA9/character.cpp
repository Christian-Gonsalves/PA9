#include "character.hpp"
#include "move.hpp"

Character::Character(string newName,int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int* newStatusEffects)
{
	name = newName;
	attack = newAttack;
	maxHealth = newMaxHealth;
	currentHealth = newCurrentHealth;
	agility = newAgility;
	accuracy = newAccuracy;
	defense = newDefense;
	if (newStatusEffects == nullptr) {
	}
	else {
		for (int i = 0; i < 10; ++i) {
			statusEffects[i] = newStatusEffects[i];
		}
	}


}

Character::~Character()
{

}

void Character::setName(const string newName)
{
	name = newName;
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

void Character::setStatusEffect(const int index, const int turns, const int strength)
{
	this->statusEffects[index] = turns;
	this->statusEffects[index + 1] = strength;
}

void Character::setMoveSet(const Move* newMoveSet)
{
	for (int i = 0; i < 12; i++) {
		moveSet[i] = newMoveSet[i];
	}
}

string Character::getName(void) const
{
	return name;
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

int Character::getStatusEffectTurns(int index)	//put in the index for the start of attribute
{
	return this->statusEffects[index];
}

int Character::getStatursEffectStrength(int index)	//put in the index for the start of attribute
{
	return this->statusEffects[index +1];

}


Move& Character::getMoveSet(void)
{
	return *this->moveSet;
}
