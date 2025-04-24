#pragma once

#include "turnWrapper.hpp"


bool TurnWrapper::runBattle() {
	Move *playerMove,
		*enemyMove;

	playerMove = choosePlayerMove();
	enemyMove = chooseEnemyMove();

	// Turn Order
	if (player.getAgility() * calculateMultiplier(player.getStatusEffectStrength(SPD_EFFECT_INDEX)) * playerMove->getSpeed() >= enemy.getAgility() * calculateMultiplier(enemy.getStatusEffectStrength(SPD_EFFECT_INDEX)) * enemyMove->getSpeed()) { // Player is first 
		playMove(player, playerMove, enemy);
		playMove(enemy, enemyMove, player);
	}
	else { // Player is second
		playMove(enemy, enemyMove, player);
		playMove(player, playerMove, enemy);
	}

	// Update Status Effects
	updateStatusEffects(player);
	updateStatusEffects(enemy);

	// Battle End Condition
	if (player.getCurrentHealth() <= 0) {
		victoryState = 1;
		return false;
	}
	if (enemy.getCurrentHealth() <= 0) {
		victoryState = 2;
		return true;
	}
}

Move* TurnWrapper::chooseEnemyMove(void) {
	return chooseEnemyMove(enemy);
}


void TurnWrapper::playMove(Character& currentCharacter, Move* playedMove, Character& recipient) {
	if (currentCharacter.getStatusEffectTurns(STN_EFFECT_INDEX) > 0) { // Stunned
		return; 
	}

	// Move Dialogue
	string playedMovePhrase = playedMove->getMovePhrase();
	if (playedMovePhrase != "") {
		std::cout << playedMovePhrase << std::endl;
	}
	
	// Does player hit attack?
	double totalMoveAccuracy = currentCharacter.getAccuracy() * playedMove->getAccuracy();
	double totalRecipientEvasion = recipient.getAgility() * calculateMultiplier(recipient.getStatusEffectStrength(SPD_EFFECT_INDEX)) * calculateMultiplier(recipient.getStatusEffectStrength(EVA_EFFECT_INDEX));

	if (getRandomInt(1, 10000) >= 10000 - ((int) 10000 * totalMoveAccuracy / totalRecipientEvasion)) { // Essentially a random number with (accuracy / evasion)% chance of occuring accurate to 3 decimal points 
		// Damage Calculations
		int totalDamage = currentCharacter.getAttack() * calculateMultiplier(currentCharacter.getStatusEffectStrength(STR_EFFECT_INDEX)) * playedMove->getPower();
		totalDamage -= recipient.getDefense() * calculateMultiplier(recipient.getStatusEffectStrength(DEF_EFFECT_INDEX));
		recipient.setCurrentHealth(recipient.getCurrentHealth() - totalDamage);
		std::cout << recipient.getName() << " took " << totalDamage << " damage!";

		// Status Effect (Currently completely overwrites a given status effect type with the new strenth and duration. This means if it was previously a strength of -2 and then a strength of 1 was applied, the final status effect would be 1)
		for (int i = 0; i < 10;  i += 2) {
			if (playedMove->getEffectTurns(i) != 0) {
				recipient.setStatusEffect(i, playedMove->getEffectTurns(i), playedMove->getEffectStrength(i));
			}
		}
	}
	else {
		std::cout << currentCharacter.getName() << " missed!" << std::endl;
	}

	playedMove->setCurMoveCount(playedMove->getCurMoveCount() - 1);
}

void TurnWrapper::updateStatusEffects(Character &currentCharacter) {
	for (int i = 0; i < 10; i += 2) {
		if (currentCharacter.getStatusEffectTurns(i) > 0) {
			currentCharacter.setStatusEffect(i, currentCharacter.getStatusEffectTurns(i) - 1, currentCharacter.getStatusEffectStrength(i));

			if (currentCharacter.getStatusEffectTurns(i) <= 0) { // Became 0 after turn passed
				currentCharacter.setStatusEffect(i, 0, 0);
			}
		}
	}
}

Move* TurnWrapper::chooseEnemyMove(EnemyCharacter& enemyIn) {
	int totalMoves = enemyIn.getMoveCount();
	Move* localArray[12] = {};
	Move* enemyMove;
	defaultMoveSetup();
	int j = 0;

	for (int i = 0; i < totalMoves && j < 12; ++i) {
		Move& m = enemyIn.getMoveSet()[i];
		if (m.getCurMoveCount() != 0){	//checks if the move in the array has moves left to be used
			if (m.getMoveType() != enemyIn.getLastTypeUsed()) {	//if it does checks to see if it 
																//is the same as last used move
				localArray[j++] = &m;	//adds the move to the local array
			}
		}
	}
	if(localArray[0] == nullptr) {
		enemyMove = &struggle;
	}
	else {
		enemyMove = localArray[getRandomInt(0, j - 1)];	//selects which move the enemy will use
		enemyIn.setLastTypeUsed(enemyMove->getMoveType());	//sets the enemys last used move type
		for (int i = 0; i < j+1; ++i) {
			//if (enemyIn.getMoveSet()[i].getMoveName() == enemyMove->getMoveName()) {
			//	enemyIn.getMoveSet()[i].setCurMoveCount(enemyMove->getCurMoveCount() - 1);
			//}
		}

	}

	return enemyMove;
}

void TurnWrapper::defaultMoveSetup(void)
{
	string name = "struggle", phrase = "yam struggling";

	Move tempMove(name, phrase, 0, 0, 0, 10, 'd');
	this->struggle = tempMove;

}

Move* TurnWrapper::choosePlayerMove() {


}

void TurnWrapper::playMove(Character& recipiant, Character& attacker)
{
	this->playMove(attacker, this->chooseEnemyMove(), recipiant);
}

int TurnWrapper::getRandomInt(int min, int max) {
	return std::rand() % (max - min + 1) + min;
}

double TurnWrapper::calculateMultiplier(int strength) {
	return 1 + 0.25 * strength;
}