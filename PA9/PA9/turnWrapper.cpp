#pragma once

#include "turnWrapper.hpp"

bool TurnWrapper::runBattle() {
	Move *playerMove,
		*enemyMove;

	while (1) { // while loop ends with last conditionals
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
			return false;
		}
		if (enemy.getCurrentHealth() <= 0) {
			return true;
		}
	}
}

void TurnWrapper::playMove(Character& currentCharacter, Move* playedMove, Character& recipient) {
	if (currentCharacter.getStatusEffectTurns(STN_EFFECT_INDEX) >= 0) { // Stunned
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

Move* TurnWrapper::chooseEnemyMove() {
	
}

Move* TurnWrapper::choosePlayerMove() {


}

int TurnWrapper::getRandomInt(int min, int max) {
	return std::rand() % (max - min + 1) + min;
}

double TurnWrapper::calculateMultiplier(int strength) {
	return 1 + 0.25 * strength;
}

