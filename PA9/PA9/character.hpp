#pragma once

#define STR_EFFECT_INDEX 0 
#define DEF_EFFECT_INDEX 2
#define SPD_EFFECT_INDEX 4
#define EVA_EFFECT_INDEX 6
#define STN_EFFECT_INDEX 8

#include "move.hpp"



class Character {
public:
	Character(string newName  = "", int newAttack = 0, int newMaxHealth = 0, int newCurrentHealth = 0, int newAgility = 0, int newAccuracy = 0,
		int newDefense = 0, int newMoveCnt = 0, int* newStatusEffects = nullptr, char newLastTypeUsed='\0');
	~Character();

	void setName(const string newName);
	void setAttack(const int newAttack);
	void setMaxHealth(const int newMaxHealth);
	void setCurrentHealth(const int newCurHealth);
	void setAgility(const int newAgility);
	void setAccuracy(const int newAccuracy);
	void setDefense(const int newDefense);
	void setMoveCount(const int newCount);
	void setStatusEffectArray(const int* newArray);
	void setStatusEffect(const int index, const int turns, const int strength);
	//index is where the turns will be held, index+1 is strength, [0] is attack turns, [1] is attack modifier
	// ex index = 0, strength = .25, turns = 1, ==> [0] = 1. [1] = .25
	void setMoveSet(Move* newMoveSet);
	void setLastTypeUsed(char newLastTypeUsed);

	string getName(void) const;
	int getAttack(void) const;
	int getMaxHealth(void) const;
	int getCurrentHealth(void) const;
	int getAgility(void) const;
	int	getAccuracy(void) const;
	int getDefense(void) const;
	int getMoveCount(void) const;
	const int* getStatusEffectArray(void) const;
	int getStatusEffectTurns(int index);
	int getStatusEffectStrength(int index);
	Move* getMoveSet(void);
	char getLastTypeUsed(void) const;

	void readFromFile(string fileName);
	Character& operator= (Character& rhs);

	/*Sorts moves from moveset so that all defense type moves take up the first 4 elements, strength the next 4, and agility the last 4*/
	void sortMoves();

private:
	string name;
	int attack;	//base attack of character attack
	int maxHealth;	//stores max health of character
	int currentHealth;	//holds current health of character
	int agility;	//base agility stat
	int accuracy;	//base accuracy stat
	int defense;	//base defense stat
	int moveCount;
    int statusEffects [10];	//an array for checking which status effects character has. Each status effect has 2 elements. First if for turn duration, second is intensity. 0: str; 2: def; 4: spd; 6: eva; 8: stun; 
	Move moveSet[12];	//an array of moves that the charcater has access to
	// the chracter model
	char lastTypeUsed; // type of last move used 
};

