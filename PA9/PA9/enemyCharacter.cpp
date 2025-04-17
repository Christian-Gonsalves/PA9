#include "enemyCharacter.hpp"

void EnemyCharacter::setCatchPhrase(const string newPhrase)
{
	catchPhrase = newPhrase;
}

string EnemyCharacter::getCatchPhrase(void) const
{
	return catchPhrase;
}

void EnemyCharacter::readFromFile(EnemyCharacter& n, ifstream& instream)
{	
	string tempName = "", tempAtt = "", tempMxHp = "", tempCurrHp = "", tempAgil = "", tempAcc = "", tempDef = "",
		tempPharse = "", tempMoveName = "";
	Moves tempMove[6];
	

	getline(instream, tempName, ',');
	getline(instream, tempAtt, ',');
	getline(instream, tempMxHp, ',');
	getline(instream, tempCurrHp, ',');
	getline(instream, tempAgil, ',');
	getline(instream, tempAcc, ',');
	getline(instream, tempDef, ',');
	getline(instream, tempPharse, ',');

	n.setName(tempName);
	n.setAttack(stoi(tempAtt));
	n.setMaxHealth(stoi(tempMxHp));
	n.setCurrentHealth(stoi(tempCurrHp));
	n.setAgility(stoi(tempAgil));
	n.setAccuracy(stoi(tempAcc));
	n.setDefense(stoi(tempDef));
	n.setCatchPhrase(tempPharse);

	for (int i = 0; i < 4; i++) {
		getline(instream, tempMoveName, ',');
		tempMove[i].setMoveName(tempMoveName);
		//get move data from database
	}
	getline(instream, tempMoveName, ',');
	tempMove[5].setMoveName(tempMoveName);
	//get move data from database

}
