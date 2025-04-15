#pragma once
#include "move.hpp"



class Character {
public:
	Character(int newAttack = 0, int newMaxHealth = 0, int newCurrentHealth = 0, int newAgility = 0, int newAccuracy = 0, 
		int newDefense = 0, int* newStatusEffects = {0});
	~Character();


private:
	int attack;	//base attack of character attack
	int maxHealth;	//stores max health of character
	int currentHealth;	//holds current health of character
	int agility;	//base agility stat
	int accuracy;	//base accuracy stat
	int defense;	//base defense stat
	int statusEffects [6];	//an array for checking which status effects character has
	Moves MoveSet[6];	//an array of moves that the charcater has access to

	// the chracter model

};

