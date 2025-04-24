<<<<<<< HEAD
#include "enemyCharacter.hpp"

EnemyCharacter::EnemyCharacter(string newName, string newPhrase, int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int* newStatusEffects)
{
	Character(newName, newAttack, newMaxHealth, newCurrentHealth, newAgility, newAccuracy, newDefense, newStatusEffects);
	catchPhrase = newPhrase;
}

EnemyCharacter::~EnemyCharacter()
{
}
=======
#pragma once
#include "character.hpp"

class EnemyCharacter : public Character {
public:
	EnemyCharacter(string newName = "", string newPhrase = "", int newAttack = 0, int newMaxHealth = 0, int newCurrentHealth = 0, int newAgility = 0, int newAccuracy = 0,
		int newDefense = 0, int newMoveCnt = 0, int* newStatusEffects = nullptr, char newLastTypeUsed='\0');

	~EnemyCharacter();
		
	void setCatchPhrase(const string newPhrase);
>>>>>>> andres-2

void EnemyCharacter::setCatchPhrase(const string newPhrase)
{
	catchPhrase = newPhrase;
}

<<<<<<< HEAD
string EnemyCharacter::getCatchPhrase(void) const
{
	return catchPhrase;
}
=======
	void readFromFile(string fileName);
>>>>>>> andres-2

void EnemyCharacter::readFromFile(string fileName)
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
	getline(instream, tempPhrase, '\n');

	this->setName(tempName);
	this->setAttack(stoi(tempAtt));
	this->setMaxHealth(stoi(tempMxHp));
	this->setCurrentHealth(stoi(tempCurrHp));
	this->setAgility(stoi(tempAgil));
	this->setAccuracy(stoi(tempAcc));
	this->setDefense(stoi(tempDef));
	this->setCatchPhrase(tempPhrase);

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

		if (i == 0 || tempName != tempMove[i - 1].getMoveName()) {	//if the line is not empty
			tempMove[i].setMoveName(tempName);
			tempMove[i].setMovePhrase(tempPhrase);
			tempMove[i].setPower(stof(tempPow));
			tempMove[i].setSpeed(stof(tempSpd));
			tempMove[i].setAccuracy(stof(tempAcc));
			tempMove[i].setMoveCount(stoi(tempCnt));
			tempMove[i].setMoveType(tempType[0]);
			tempMove[i].setEffectAttribute(stoi(tempInd), stoi(tempDur), stoi(tempStr));
		}
		else {
			break;
		}
	}

	this->setMoveSet(tempMove);

	instream.close();
}
};