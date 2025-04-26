#pragma once

#include "enemyCharacter.hpp"
#include "battleScreen.hpp"




class TurnWrapper {
public:
		
	TurnWrapper(EnemyCharacter& newEnemy, Character &newPlayer, BattleScreen *newScreen=nullptr, sf::RenderWindow *newWindow=nullptr, bool newVictoryState=false, int newDifficulty=0) : enemy(newEnemy), player(newPlayer), screen(newScreen), window(newWindow), victoryState(newVictoryState), mDifficulty(newDifficulty) { defaultMoveSetup(); };

	~TurnWrapper() {};

	// Main loop of battle returns true if player won, false if lost
	bool runBattle();

	void setPlayer(Character& newPlayer) { player = newPlayer; }
	void setEnemy(EnemyCharacter& newEnemy) { enemy = newEnemy; }

	// Public interface for testing purposes
	Move* chooseEnemyMove(void);

	// Public interface for testing purposes
	void defaultMoveSetup(void);

	void playMove(Character& recipiant, Character& attacker);

private:
	int mDifficulty; // Scales stats based on player overall progress (not currently implemented)
	int victoryState; // 0 default; 1 if enemy won, 2 if player won
	// Not pointers because we will make changes that we don't want to save throughout multiple battles

	Character player;
	EnemyCharacter enemy;
	Move struggle; // Default move used if no other move is available

	BattleScreen *screen;
	sf::RenderWindow *window;

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

	/*Function ends battle gracefully*/
	void endBattle(bool playerVictory);

	/*Updates, draws, and displays screen*/
	void display();

	/*Pauses until user presses enter on dialogue box to continue game*/
	void promptDialogueBoxInput();

	// Creates a std::string for the descrption of a move using its index
	std::string createMoveBoxDescription(int index);

	// Returns a std::string based on strength
	std::string createStatusEffectStrengthSymbol(int strength);

	/*Calculates the type multiplier. If a type is stronger than another (->), it deals 1.25x damage. Vice versa deals 0.75x damage
	Type of Move Used vs Last Type Used by enemy
	Def -> Str
	Str -> Agi
	Agi -> Def
	*/
	double calculateTypeMultiplier(char typeUsed, char enemyLastTypeUsed);

	// Converts effect index to name
	std::string convertEffectIndexToName(int index);
};