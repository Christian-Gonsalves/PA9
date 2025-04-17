#pragma once
#include "move.hpp"



class Character {
public:
	Character(int newAttack = 0, int newMaxHealth = 0, int newCurrentHealth = 0, int newAgility = 0, int newAccuracy = 0, 
		int newDefense = 0, int* newStatusEffects = {0});
	~Character();

	void setAttack(const int newAttack);
	void setMaxHealth(const int newMaxHealth);
	void setCurrentHealth(const int newCurHealth);
	void setAgility(const int newAgility);
	void setAccuracy(const int newAccuracy);
	void setDefense(const int newDefense);
	void setStatusEffects(const int& newStatusEffect);
	void setMoveSet(const Moves& newMoveSet);

	int getAttack(void) const;
	int getMaxHealth(void) const;
	int getCurrentHealth(void) const;
	int getAgility(void) const;
	int	getAccuracy(void) const;
	int getDefense(void) const;
	int& getStatusEffect(void);
	Moves& getMoveSet(void);


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
