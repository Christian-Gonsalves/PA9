#pragma once

#include "turnWrapper.hpp"


void TurnWrapper::runBattle() {
	Move *playerMove = nullptr,
		*enemyMove = nullptr;

	bool isEndOfBattle = false;
	int playerVictory = false;

	screen->getDialogueBox()->setText(enemy.getName() + ": " + enemy.getCatchPhrase());
	display();
	promptDialogueBoxInput();

	while (!isEndOfBattle) {
		if(player.getStatusEffectStrength(STN_EFFECT_INDEX) < 1) {
			playerMove = choosePlayerMove();
		}
		
		if (enemy.getStatusEffectStrength(STN_EFFECT_INDEX) < 1) {
			enemyMove = chooseEnemyMove();
		}
		

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
		if (enemy.getCurrentHealth() <= 0) { // Player wins in situation where both hit zero hp on same turn
			isEndOfBattle = true;
		}
		else if (player.getCurrentHealth() <= 0) {
			playerVictory = true;
			isEndOfBattle = true;
		}
	}

	endBattle(playerVictory);
}

Move* TurnWrapper::chooseEnemyMove(void) {
	return chooseEnemyMove(enemy);
}


void TurnWrapper::playMove(Character& currentCharacter, Move* playedMove, Character& recipient) {
	screen->setShowingMainDialogueBox(true); // Continue to show 

	if (currentCharacter.getStatusEffectTurns(STN_EFFECT_INDEX) > 0) { // Stunned
		return; 
	}

	if (playedMove->getMoveName() == "struggle") {
		screen->getDialogueBox()->setText(currentCharacter.getName() + " struggled!\n");
		display();
		promptDialogueBoxInput();
		
		return;
	}
	screen->getDialogueBox()->setText(currentCharacter.getName() + " used " + playedMove->getMoveName() + "!\n");
	display();
	promptDialogueBoxInput();
	screen->setShowingMainDialogueBox(true); // Continue to show 

	// Move Dialogue
	string playedMovePhrase = playedMove->getMovePhrase();
	if (playedMovePhrase != "") {
		screen->getDialogueBox()->setText(currentCharacter.getName() + ": " + playedMovePhrase + "\n");
		display();
		promptDialogueBoxInput();
		screen->setShowingMainDialogueBox(true); // Continue to show 
	}
	
	// Does player hit attack?
	double totalMoveAccuracy = currentCharacter.getAccuracy() * playedMove->getAccuracy();
	double totalRecipientEvasion = recipient.getAgility() * calculateMultiplier(recipient.getStatusEffectStrength(SPD_EFFECT_INDEX)) * calculateMultiplier(recipient.getStatusEffectStrength(EVA_EFFECT_INDEX));

	if (getRandomInt(1, 10000) >= 10000 - ((int) 10000 * totalMoveAccuracy / totalRecipientEvasion)) { // Essentially a random number with (accuracy / evasion)% chance of occuring accurate to 3 decimal points 
		// Damage Calculations
		int totalDamage = currentCharacter.getAttack() * calculateMultiplier(currentCharacter.getStatusEffectStrength(STR_EFFECT_INDEX)) * playedMove->getPower();
		totalDamage -= recipient.getDefense() * calculateMultiplier(recipient.getStatusEffectStrength(DEF_EFFECT_INDEX));
		recipient.setCurrentHealth(recipient.getCurrentHealth() - totalDamage);

		screen->getDialogueBox()->setText(recipient.getName() + " took " + std::to_string(totalDamage) + " damage!");

		// Status Effect (Currently completely overwrites a given status effect type with the new strenth and duration. This means if it was previously a strength of -2 and then a strength of 1 was applied, the final status effect would be 1)
		for (int i = 0; i < 10;  i += 2) {
			if (playedMove->getEffectTurns(i) != 0) {
				recipient.setStatusEffect(i, playedMove->getEffectTurns(i), playedMove->getEffectStrength(i));
			}
		}
	}
	else {
		screen->getDialogueBox()->setText(currentCharacter.getName() + " missed!\n");
	}

	display();
	promptDialogueBoxInput();

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
	Move* selectedMove = nullptr;
	Move* sortedArray[12] = {nullptr};
	bool validMove = false, hasAvailableMove = false;
	int numAtkMoves = 0, numDefMoves = 0, numAgiMoves = 0,
		selectedTypeIndex = 0;
	char tempMoveType = '\0';

	// Any available moves?
	for (int i = 0; i < player.getMoveCount(); i++) {
		if (player.getMoveSet()[i].getCurMoveCount() > 0) {
			hasAvailableMove = true;
		}
	}
	if (!hasAvailableMove) {
		return &struggle;
	}

	// Sorting
	for (int i = 0; i < 12; i++) {
		tempMoveType = player.getMoveSet()[i].getMoveType();
		switch (tempMoveType) {
			case 's':
				sortedArray[numAtkMoves] = &(player.getMoveSet()[i]);
				numAtkMoves++;
				break;
			case 'd':
				sortedArray[numDefMoves + 4] = &(player.getMoveSet()[i]);
				numDefMoves++;
				break;
			case 'a':
				sortedArray[numAgiMoves + 4] = &(player.getMoveSet()[i]);
				numAgiMoves++;
				break;
			default:
				std::cout << "Error in TurnWrapper::choosePlayerMove(): player has move of invalid type." << std::endl;
				break;
		}
	}

	while (!validMove) {
		selectedTypeIndex = screen->getSelectedTypeIndex();

		if (sortedArray[selectedTypeIndex] == nullptr) {
			screen->getMove1Box()->setText("");
		}
		else {
			screen->getMove1Box()->setText("Z.\n" + sortedArray[selectedTypeIndex]->getMoveName());
		}

		if (sortedArray[selectedTypeIndex + 1] == nullptr) {
			screen->getMove2Box()->setText("");
		}
		else {
			screen->getMove2Box()->setText("X.\n" + sortedArray[selectedTypeIndex + 1]->getMoveName());
		}

		if (sortedArray[selectedTypeIndex + 2] == nullptr) {
			screen->getMove3Box()->setText("");
		}
		else {
			screen->getMove3Box()->setText("C.\n" + sortedArray[selectedTypeIndex + 2]->getMoveName());
		}

		if (sortedArray[selectedTypeIndex + 3] == nullptr) {
			screen->getMove4Box()->setText("");
		}
		else {
			screen->getMove4Box()->setText("V.\n" + sortedArray[selectedTypeIndex + 3]->getMoveName());
		}
		

		display();
		screen->handleInput(*window);
		selectedMove = sortedArray[screen->getSelectedMoveIndex() + 4 * selectedTypeIndex];

		if (selectedMove != nullptr) {
			if (selectedMove->getMoveType() != player.getLastTypeUsed() && selectedMove->getCurMoveCount() > 0) {
				validMove = true;
			}
		}
	}

	screen->setShowingMainDialogueBox(true);

	return selectedMove;
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

void TurnWrapper::endBattle(bool playerVictory) {
	screen->setShowingMainDialogueBox(true);

	if (playerVictory) {
		screen->getDialogueBox()->setText("Player victory!!!");
	}
	else {
		screen->getDialogueBox()->setText("Player defeated :(");
	}

	display();
	promptDialogueBoxInput();


}

void TurnWrapper::display() {
	window->clear();
	screen->update();
	screen->draw(*window);
	window->display();
}

void TurnWrapper::promptDialogueBoxInput() {
	while (screen->isShowingMainDialogBox()) {
		screen->handleInput(*window);
	}
}

