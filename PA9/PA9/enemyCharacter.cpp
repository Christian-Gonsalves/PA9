#include "enemyCharacter.hpp"

<<<<<<< HEAD
EnemyCharacter::EnemyCharacter(string newName, string newPhrase, int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int* newStatusEffects)
{
	Character(newName, newAttack, newMaxHealth, newCurrentHealth, newAgility, newAccuracy, newDefense, newStatusEffects);
	catchPhrase = newPhrase;
=======
EnemyCharacter::EnemyCharacter(string newName, string newPhrase, int newAttack, int newMaxHealth, int newCurrentHealth, int newAgility, int newAccuracy, int newDefense, int newMoveCnt, int* newStatusEffects, char newLastTypeUsed)
	: Character(newName, newAttack, newMaxHealth, newCurrentHealth, newAgility, newAccuracy, newDefense, newMoveCnt, newStatusEffects, newLastTypeUsed),
		catchPhrase(newPhrase)
{
>>>>>>> andres-2
}

EnemyCharacter::~EnemyCharacter()
{
}

void EnemyCharacter::setCatchPhrase(const string newPhrase)
{
	catchPhrase = newPhrase;
}

string EnemyCharacter::getCatchPhrase(void) const
{
	return catchPhrase;
}

void EnemyCharacter::readFromFile(string fileName)
<<<<<<< HEAD
{
	ifstream instream(fileName);
	string tempName = "", tempAtt = "", tempMxHp = "", tempCurrHp = "", tempAgil = "", tempAcc = "", tempDef = "",
		tempPhrase = "", tempMoveName = "", tempPow = "", tempSpd = "", tempCnt = "", tempType = "",
		tempInd = "", tempDur = "", tempStr = "";
	Move tempMove[12];

=======
{	
	ifstream instream(fileName);
	string tempName = "", tempAtt = "", tempMxHp = "", tempCurrHp = "", tempAgil = "", tempAcc = "", tempDef = "",
		tempPhrase = "", tempMoveName = "", tempPow="", tempSpd="", tempCnt = "", tempType = "",
		tempInd = "", tempDur = "", tempStr = "";
	Move tempMove[12];
	
>>>>>>> andres-2

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

<<<<<<< HEAD
		if (i == 0 || tempName != tempMove[i - 1].getMoveName()) {	//if the line is not empty
			tempMove[i].setMoveName(tempName);
			tempMove[i].setMovePhrase(tempPhrase);
			tempMove[i].setPower(stof(tempPow));
			tempMove[i].setSpeed(stof(tempSpd));
			tempMove[i].setAccuracy(stof(tempAcc));
			tempMove[i].setMoveCount(stoi(tempCnt));
			tempMove[i].setMoveType(tempType[0]);
			tempMove[i].setEffectAttribute(stoi(tempInd), stoi(tempDur), stoi(tempStr));
=======
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
>>>>>>> andres-2
		}
		else {
			break;
		}
<<<<<<< HEAD
=======
		
>>>>>>> andres-2
	}

	this->setMoveSet(tempMove);

	instream.close();
}

EnemyCharacter& EnemyCharacter::operator=(const EnemyCharacter& rhs)
{
	this->setName(rhs.getName());
	this->setCatchPhrase(rhs.getCatchPhrase());
	this->setAttack(rhs.getAttack());
	this->setMaxHealth(rhs.getMaxHealth());
	this->setCurrentHealth(rhs.getCurrentHealth());
	this->setAgility(rhs.getAgility());
	this->setAccuracy(rhs.getAccuracy());
	this->setDefense(rhs.getDefense());
	this->setMoveCount(rhs.getMoveCount());
	this->setStatusEffectArray(rhs.getStatusEffectArray());
	this->setMoveSet(rhs.getMoveSet());
	this->setLastTypeUsed(rhs.getLastTypeUsed());

	return *this;
}
