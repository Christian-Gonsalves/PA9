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
		tempMove = "";

	getline(instream, tempName, ',');


}
