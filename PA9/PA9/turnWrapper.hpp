#pragma once

#include "character.hpp"
#include "battleScreen.hpp"

class TurnWrapper {
public:

	TurnWrapper(Character newEnemy, Character newPlayer) : enemy(newEnemy), player(newPlayer) {};

	~TurnWrapper() {};

	/*Runs Battle
		@returns true if player won;
				 false otherwise.*/
	bool runBattle();

private:
	int mDifficulty; // Scales stats based on player overall progress

	// Not pointers because we will make changes that we don't want to save throughout multiple battles

	Character enemy,
		player;

	/*Chooses which move an enemey makes
		@returns reference to move*/
	Move* chooseEnemyMove();

	/*Chooses which move an enemey makes
	@returns reference to move*/
	Move* choosePlayerMove();

	/*Executes all the code associated for currentCharacter's playedMove against a recipient character:
	1. Whether atk hits
	2. Damage done
	3. Whether Status effect hits*/
	void playMove(Character& currentCharacter, Move* playedMove, Character& recipient);

	/*Updates the duration and, if necessary, the strength of a status effect after a turn passes*/
	void updateStatusEffects(Character& currentCharacter);

	/*Gets a random integer along the bounds min & max using std::rand()*/
	int getRandomInt(int min, int max);

	/*Calculates multiplier based on status effect strength*/
	double calculateMultiplier(int strength);

};