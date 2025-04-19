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
	getline(instream, tempPharse, '\n');

	n.setName(tempName);
	n.setAttack(stoi(tempAtt));
	n.setMaxHealth(stoi(tempMxHp));
	n.setCurrentHealth(stoi(tempCurrHp));
	n.setAgility(stoi(tempAgil));
	n.setAccuracy(stoi(tempAcc));
	n.setDefense(stoi(tempDef));
	n.setCatchPhrase(tempPharse);



}

