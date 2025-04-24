#pragma once

#include "enemyCharacter.hpp"
#include "battleScreen.hpp"




class TurnWrapper {
public:
		
	TurnWrapper(EnemyCharacter& newEnemy, Character &newPlayer, bool newVictoryState=false, int newDifficulty=0) : enemy(newEnemy), player(newPlayer), victoryState(newVictoryState), mDifficulty(newDifficulty) {};

	~TurnWrapper() {};

	/*Runs Battle
		@returns true if battle is over;
				 false otherwise*/
	bool runBattle();

	Move* chooseEnemyMove(void);
	void defaultMoveSetup(void);




private:
	int mDifficulty; // Scales stats based on player overall progress
	int victoryState; // 0 default; 1 if enemy won, 2 if player won
	// Not pointers because we will make changes that we don't want to save throughout multiple battles

	Character player;
	EnemyCharacter enemy;
	Move struggle; // Default move used if no other move is available

	/*Chooses which move an enemey makes
		@returns reference to move*/
	Move* chooseEnemyMove(EnemyCharacter& enemy);


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