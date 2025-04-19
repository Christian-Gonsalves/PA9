#include "enemyCharacter.hpp"

void EnemyCharacter::setCatchPhrase(const string newPhrase)
{
	catchPhrase = newPhrase;
}

string EnemyCharacter::getCatchPhrase(void) const
{
	return catchPhrase;
}

void EnemyCharacter::readFromFile(EnemyCharacter& n, string fileName)
{	
	ifstream instream(fileName);
	string tempName = "", tempAtt = "", tempMxHp = "", tempCurrHp = "", tempAgil = "", tempAcc = "", tempDef = "",
		tempPhrase = "", tempMoveName = "", tempPow="", tempSpd="", tempCnt = "", tempType = "",
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

	n.setName(tempName);
	n.setAttack(stoi(tempAtt));
	n.setMaxHealth(stoi(tempMxHp));
	n.setCurrentHealth(stoi(tempCurrHp));
	n.setAgility(stoi(tempAgil));
	n.setAccuracy(stoi(tempAcc));
	n.setDefense(stoi(tempDef));
	n.setCatchPhrase(tempPhrase);

	for (int i = 0; i < 11; i++) {
		getline(instream, tempName, ',');
		getline(instream, tempPhrase, ',');
		getline(instream, tempPow, ',');
		getline(instream, tempSpd, ',');
		getline(instream, tempAcc, ',');
		getline(instream, tempCnt, ',');
		getline(instream, tempType, ',');
		getline(instream, tempInd, ',');
		getline(instream, tempDur, ',');
		getline(instream, tempStr, ',');

		tempMove[i].setMoveName(tempName);
		tempMove[i].setMovePhrase(tempPhrase);
		tempMove[i].setPower(stof(tempPow));
		tempMove[i].setSpeed(stof(tempSpd));
		tempMove[i].setAccuracy(stof(tempAcc));
		tempMove[i].setMoveCount(stoi(tempCnt));
		tempMove[i].setMoveType(tempType[0]);
		tempMove[i].setEffectArray(stoi(tempInd), stoi(tempDur), stoi(tempStr));

	}



	instream.close();
}
