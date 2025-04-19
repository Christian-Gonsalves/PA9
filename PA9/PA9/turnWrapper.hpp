#pragma once

#include "character.hpp"

class TurnWrapper {
public:

	TurnWrapper(Character* newEnemy, Character* newPlayer) : enemy(newEnemy), player(newPlayer) {};

	~TurnWrapper() {};

	/*Runs Battle
		@returns true if player won;
				 false otherwise.*/
	bool runBattle();

private:
	int mDifficulty; // Scales stats based on player overall progress

	Character *enemy,
			  *player;

	/*Determines turn order based on agility stat. 
		@returns true if player is first, false otherwise*/
	bool determineTurnOrder();

	/*Chooses which move an enemey makes
		@returns reference to move*/ 
	Move& chooseEnemyMove();

	/*@returns true if battle is over; false otherwise*/
	bool isBattleOver();
};