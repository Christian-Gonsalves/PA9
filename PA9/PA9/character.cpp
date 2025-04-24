<<<<<<< HEAD
##include "character.hpp"
#include "move.hpp"

Character::Character(string newName, int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int* newStatusEffects)
=======
#include "character.hpp"
#include "move.hpp"

Character::Character(string newName,int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int newMoveCnt, int* newStatusEffects, char newLastTypeUsed)
>>>>>>> andres-2
{
	name = newName;
	attack = newAttack;
	maxHealth = newMaxHealth;
	currentHealth = newCurrentHealth;
	agility = newAgility;
	accuracy = newAccuracy;
	defense = newDefense;
<<<<<<< HEAD
	if (newStatusEffects == nullptr) {
=======
	moveCount = newMoveCnt;
	lastTypeUsed = newLastTypeUsed;
	if (newStatusEffects == nullptr) {
		for (int i = 0; i < 10; ++i) {
			statusEffects[i] = 0;
		}
>>>>>>> andres-2
	}
	else {
		for (int i = 0; i < 10; ++i) {
			statusEffects[i] = newStatusEffects[i];
		}
	}

<<<<<<< HEAD

=======
>>>>>>> andres-2
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

<<<<<<< HEAD
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
=======
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
	}
}

void Character::setLastTypeUsed(char newLastTypeUsed) {
	lastTypeUsed = newLastTypeUsed;
}

char Character::getLastTypeUsed(void) const {
	return lastTypeUsed;
>>>>>>> andres-2
}

void Character::readFromFile(string fileName)
{
	ifstream instream(fileName);
	string tempName = "", tempAtt = "", tempMxHp = "", tempCurrHp = "", tempAgil = "", tempAcc = "", tempDef = "",
		tempPhrase = "", tempMoveName = "", tempPow = "", tempSpd = "", tempCnt = "", tempType = "",
		tempInd = "", tempDur = "", tempStr = "";
	Move tempMove[12];


	getline(instream, tempName, ',');
	getline(instream, tempAtt, ',');
	getline(instream, tempMxHp, ',');
	getline(instream, tempCurrHp, ',');
	getline(instream, tempAgil, ',');
	getline(instream, tempAcc, ',');
	getline(instream, tempDef, ',');

	this->setName(tempName);
	this->setAttack(stoi(tempAtt));
	this->setMaxHealth(stoi(tempMxHp));
	this->setCurrentHealth(stoi(tempCurrHp));
	this->setAgility(stoi(tempAgil));
	this->setAccuracy(stoi(tempAcc));
	this->setDefense(stoi(tempDef));

	for (int i = 0; i < 12; i++) {
		getline(instream, tempName, ',');
		getline(instream, tempPhrase, ',');
		getline(instream, tempPow, ',');
		getline(instream, tempSpd, ',');
		getline(instream, tempAcc, ',');
		getline(instream, tempCnt, ',');
		getline(instream, tempType, ',');
		getline(instream, tempInd, ',');
		getline(instream, tempDur, ',');
		getline(instream, tempStr, '\n');

		if (tempName != this->getName()) {
			if (i == 0 || tempName != tempMove[i - 1].getMoveName()) {
				tempMove[i].setMoveName(tempName);
				tempMove[i].setMovePhrase(tempPhrase);
				tempMove[i].setPower(stof(tempPow));
				tempMove[i].setSpeed(stof(tempSpd));
				tempMove[i].setAccuracy(stof(tempAcc));
				tempMove[i].setMaxMoveCount(stoi(tempCnt));
				tempMove[i].setCurMoveCount(stoi(tempCnt));
				tempMove[i].setMoveType(tempType[0]);
				tempMove[i].setEffectAttribute(stoi(tempInd), stoi(tempDur), stoi(tempStr));
			}
			else {
				this->setMoveCount(i);
				break;
			}
		}
		else {
			break;
		}

	}

	this->setMoveSet(tempMove);

	instream.close();
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

<<<<<<< HEAD
int Character::getStatusEffectTurns(int index)	//put in the index for the start of attribute
{
	return this->statusEffects[index];
}

int Character::getStatursEffectStrength(int index)	//put in the index for the start of attribute
{
	return this->statusEffects[index + 1];
=======
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
>>>>>>> andres-2

}


<<<<<<< HEAD
Move& Character::getMoveSet(void)
{
	return *this->moveSet;
=======
Move* Character::getMoveSet(void)
{
	return this->moveSet;
>>>>>>> andres-2
}
