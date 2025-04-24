#pragma once
#include "character.hpp"

class EnemyCharacter : public Character {
public:
	EnemyCharacter(string newName = "", string newPhrase = "", int newAttack = 0, int newMaxHealth = 0, int newCurrentHealth = 0, int newAgility = 0, int newAccuracy = 0,
		int newDefense = 0, int newMoveCnt = 0, int* newStatusEffects = nullptr, char newLastTypeUsed='\0');

	~EnemyCharacter();
		
	void setCatchPhrase(const string newPhrase);

	string getCatchPhrase(void) const;

	void readFromFile(string fileName);

	EnemyCharacter& operator=(EnemyCharacter& rhs);

private:
	string catchPhrase;

};