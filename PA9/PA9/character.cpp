#include "character.hpp"
#include "move.hpp"

Character::Character(string newName,int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int newMoveCnt, int* newStatusEffects, char newLastTypeUsed)
{
	name = newName;
	attack = newAttack;
	maxHealth = newMaxHealth;
	currentHealth = newCurrentHealth;
	agility = newAgility;
	accuracy = newAccuracy;
	defense = newDefense;
	moveCount = newMoveCnt;
	lastTypeUsed = newLastTypeUsed;
	if (newStatusEffects == nullptr) {
		for (int i = 0; i < 10; ++i) {
			statusEffects[i] = 0;
		}
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

void Character::setMoveCount(const int newCount)
{
	moveCount = newCount;
}

void Character::setStatusEffect(const int index, const int turns, const int strength)
{
	this->statusEffects[index] = turns;
	this->statusEffects[index + 1] = strength;
}

void Character::setMoveSet(Move* newMoveSet)
{
	for (int i = 0; i < 12; i++) {
		moveSet[i] = newMoveSet[i];
	//	cout << moveSet[i].getMoveName() << endl;
	}
}

void Character::setLastTypeUsed(char newLastTypeUsed) {
	lastTypeUsed = newLastTypeUsed;
}

char Character::getLastTypeUsed(void) const {
	return lastTypeUsed;
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

int Character::getMoveCount(void) const
{
	return moveCount;
}

int Character::getStatusEffectTurns(int index)	//put in the index for the start of attribute
{
	return this->statusEffects[index];
}

int Character::getStatusEffectStrength(int index)	//put in the index for the start of attribute
{
	return this->statusEffects[index +1];

}


Move* Character::getMoveSet(void)
{
	return this->moveSet;
}
