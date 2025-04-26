#pragma once

#include "turnWrapper.hpp"

bool TurnWrapper::runBattle() {
	Move *playerMove = nullptr,
		*enemyMove = nullptr;

	bool isEndOfBattle = false;
	int playerVictory = false;

	screen->getDialogueBox()->formattedSetText(enemy.getName() + ": " + enemy.getCatchPhrase());
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
			playerVictory = true;
		}
		else if (player.getCurrentHealth() <= 0) {
			isEndOfBattle = true;
		}
	}

	endBattle(playerVictory);
	return playerVictory;
}

Move* TurnWrapper::chooseEnemyMove(void) {
	return chooseEnemyMove(enemy);
}


void TurnWrapper::playMove(Character& currentCharacter, Move* playedMove, Character& recipient) {
	screen->setShowingMainDialogueBox(true); // Continue to show 
	std::string damageMessage;

	if (currentCharacter.getStatusEffectTurns(STN_EFFECT_INDEX) > 0) { // Stunned
		return; 
	}

	if (playedMove->getMoveName() == "struggle") {
		screen->getDialogueBox()->formattedSetText(currentCharacter.getName() + " struggled!\n");
		display();
		promptDialogueBoxInput();
		
		return;
	}
	screen->getDialogueBox()->formattedSetText(currentCharacter.getName() + " used " + playedMove->getMoveName() + "!\n");
	display();
	promptDialogueBoxInput();
	screen->setShowingMainDialogueBox(true); // Continue to show 

	// Move Dialogue
	string playedMovePhrase = playedMove->getMovePhrase();
	if (playedMovePhrase != "") {
		screen->getDialogueBox()->formattedSetText(currentCharacter.getName() + ": " + playedMovePhrase + "\n");
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

		double typeMultiplier = calculateTypeMultiplier(playedMove->getMoveType(), recipient.getLastTypeUsed());
		totalDamage *= typeMultiplier;

		std::cout << "Actor: " << playedMove->getMoveType() << " Recipient: " << recipient.getLastTypeUsed() << " Multiplier: " << typeMultiplier << std::endl;

		damageMessage += "Move was ";
		if (typeMultiplier > 1.00) {
			damageMessage += "effective";
		}
		else if (typeMultiplier < 1.00) {
			damageMessage += "ineffective";
		}
		damageMessage += "! ";

		if (totalDamage < 0) {
			totalDamage = 0;
		}

		recipient.setCurrentHealth(recipient.getCurrentHealth() - totalDamage);

		damageMessage += recipient.getName() + " took " + std::to_string(totalDamage) + " damage! ";

		// Status Effect (Currently completely overwrites a given status effect type with the new strenth and duration. This means if it was previously a strength of -2 and then a strength of 1 was applied, the final status effect would be 1)
		for (int i = 0; i < 8;  i += 2) {
			if (playedMove->getEffectStrength(i) < 0) {
				recipient.setStatusEffect(i, playedMove->getEffectTurns(i), playedMove->getEffectStrength(i));
				damageMessage += recipient.getName() + "'s " + convertEffectIndexToName(i) + " has been decreased! ";
			}
			else if (playedMove->getEffectStrength(i) > 0) {
				currentCharacter.setStatusEffect(i, playedMove->getEffectTurns(i), playedMove->getEffectStrength(i));
				damageMessage += currentCharacter.getName() + "'s " + convertEffectIndexToName(i) + " has been increased! ";
			}
			
		}
		
		if (playedMove->getEffectStrength(STN_EFFECT_INDEX) > 0) {
			recipient.setStatusEffect(STN_EFFECT_INDEX, playedMove->getEffectTurns(STN_EFFECT_INDEX), playedMove->getEffectStrength(STN_EFFECT_INDEX));
			damageMessage += currentCharacter.getName() + " has been stunned!!! ";
		}

		screen->getDialogueBox()->formattedSetText(damageMessage);
	}
	else {
		screen->getDialogueBox()->formattedSetText(currentCharacter.getName() + " missed!\n");
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	screen->setEnemyMaxHP(enemy.getMaxHealth());
	screen->setEnemyCurHP(enemy.getCurrentHealth());
	screen->setPlayerMaxHP(player.getMaxHealth());
	screen->setPlayerCurHP(player.getCurrentHealth());


	display();
	promptDialogueBoxInput();

	playedMove->setCurMoveCount(playedMove->getCurMoveCount() - 1);
}

void TurnWrapper::updateStatusEffects(Character &currentCharacter) {
	screen->setShowingMainDialogueBox(true);
	std::string effectEndMessage;

	for (int i = 0; i < 10; i += 2) {
		if (currentCharacter.getStatusEffectTurns(i) > 0) {
			currentCharacter.setStatusEffect(i, currentCharacter.getStatusEffectTurns(i) - 1, currentCharacter.getStatusEffectStrength(i));

			if (currentCharacter.getStatusEffectTurns(i) <= 0) { // Became 0 after turn passed
				currentCharacter.setStatusEffect(i, 0, 0);
				effectEndMessage += currentCharacter.getName();
				if (i != STN_EFFECT_INDEX) {
					effectEndMessage += "'s " + convertEffectIndexToName(i) + " is back to normal. ";
				}
				else {
					effectEndMessage += " is no longer stunned. ";
				}
				
			}
		}
	}
	if (effectEndMessage != "") { // is not blank
		screen->getDialogueBox()->formattedSetText(effectEndMessage);
		display();
		promptDialogueBoxInput();
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
	Move* selectedMove = nullptr, *playerMoveSet = player.getMoveSet();
	bool validMove = false, hasAvailableMove = false;
	int selectedTypeIndex = 0, selectedMoveIndex = -1;

	// Any available moves?
	for (int i = 0; i < player.getMoveCount(); i++) {
		if (player.getMoveSet()[i].getCurMoveCount() > 0) {
			hasAvailableMove = true;
		}
	}
	if (!hasAvailableMove) {
		return &struggle;
	}

	while (!validMove) {
		selectedTypeIndex = screen->getSelectedTypeIndex();
		selectedMoveIndex = screen->getSelectedMoveIndex();

		if (playerMoveSet[selectedTypeIndex * 4].getMoveName() == "") {
			screen->getMove1Box()->setText("");
		}
		else {
			screen->getMove1Box()->setText("Z.\n" + createMoveBoxDescription(selectedTypeIndex * 4));
		}

		if (playerMoveSet[selectedTypeIndex * 4 + 1].getMoveName() == "") {
			screen->getMove2Box()->setText("");
		}
		else {
			screen->getMove2Box()->setText("X.\n" + createMoveBoxDescription(selectedTypeIndex * 4 + 1));
		}

		if (playerMoveSet[selectedTypeIndex * 4 + 2].getMoveName() == "") {
			screen->getMove3Box()->setText("");
		}
		else {
			screen->getMove3Box()->setText("C.\n" + createMoveBoxDescription(selectedTypeIndex * 4 + 2));
		}

		if (playerMoveSet[selectedTypeIndex * 4 + 3].getMoveName() == "") {
			screen->getMove4Box()->setText("");
		}
		else {
			screen->getMove4Box()->setText("V.\n" + createMoveBoxDescription(selectedTypeIndex * 4 + 3));
		}

		display();
		screen->handleInput(*window);

		if (selectedMoveIndex != -1) {
			selectedMove = &(playerMoveSet[selectedMoveIndex + 4 * selectedTypeIndex]);
		}

		if (selectedMove != nullptr) {
			if (selectedMove->getMoveName() != "" && selectedMove->getMoveType() != player.getLastTypeUsed() && selectedMove->getCurMoveCount() > 0) {
				validMove = true;
			}
		}

	}

	screen->setShowingMainDialogueBox(true);



	player.setLastTypeUsed(selectedMove->getMoveType()); // If an attack misses, it will still have used that type. Maybe change?
	screen->setSelectedMoveIndex(-1); // So it doesn't repeatedly enter same move after next turn
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
		screen->getDialogueBox()->formattedSetText("Player victory!!!");
	}
	else {
		screen->getDialogueBox()->formattedSetText("Player defeated :(");
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




std::string TurnWrapper::createMoveBoxDescription(int index) {
	Move* moveSet = player.getMoveSet();
	std::string description = "\n" + moveSet[index].getMoveName();



	if (moveSet[index].getMoveName().length() < 19) {
		for (int i = moveSet[index].getMoveName().length(); i < 19; i++){
			description += " ";
			}
	}

	description += "Moves: " + std::to_string(moveSet[index].getCurMoveCount()).substr(0, 2) + "\n\n" + "Power: " + std::to_string(moveSet[index].getPower()).substr(0, 4) +
		"\t\tSpeed: " + std::to_string(moveSet[index].getSpeed()).substr(0, 4) + "\n\nAccuracy: " + std::to_string(moveSet[index].getAccuracy()).substr(0, 4);
	if (moveSet[index].getEffectArray()[STR_EFFECT_INDEX] > 0) {
		description += "\t Str: " + createStatusEffectStrengthSymbol(moveSet[index].getEffectArray()[STR_EFFECT_INDEX]).substr(0, 4);
		}
	if (moveSet[index].getEffectArray()[DEF_EFFECT_INDEX] > 0) {
		description += "\t Def: " + createStatusEffectStrengthSymbol(moveSet[index].getEffectArray()[DEF_EFFECT_INDEX]).substr(0, 4);
	}
	if (moveSet[index].getEffectArray()[SPD_EFFECT_INDEX] > 0) {
		description += "\t Spd: " + createStatusEffectStrengthSymbol(moveSet[index].getEffectArray()[SPD_EFFECT_INDEX]).substr(0, 4);
	}
	if (moveSet[index].getEffectArray()[EVA_EFFECT_INDEX] > 0) {
		description += "\t Eva: " + createStatusEffectStrengthSymbol(moveSet[index].getEffectArray()[EVA_EFFECT_INDEX]).substr(0, 4);
	}
	if (moveSet[index].getEffectArray()[STN_EFFECT_INDEX] > 0) {
		description += "\t Stn: " + createStatusEffectStrengthSymbol(moveSet[index].getEffectArray()[STN_EFFECT_INDEX]).substr(0, 4);
	}

	return description;
}

std::string TurnWrapper::createStatusEffectStrengthSymbol(int strength) {
	std::string symbol = "";
	if (strength == 0) {
		symbol = "-";
	}
	else if (strength < 0) {
		strength *= -1;
		for (int i = 0; i < strength; i++) {
			symbol += "v";
		}
	}
	else {
		for (int i = 0; i < strength; i++) {
			symbol += "^";
		}
	}

	return symbol;
}

double TurnWrapper::calculateTypeMultiplier(char typeUsed, char enemyLastTypeUsed) {
	double multiplierIntensity = 0.25;

	switch (typeUsed) {
	case 'd':
		if (enemyLastTypeUsed == 'a') { // Weakness
			multiplierIntensity *= -1;
		}
		break;
	case 's':
		if (enemyLastTypeUsed == 'd') {
			multiplierIntensity *= -1;
		}
		break;
	case 'a':
		if (enemyLastTypeUsed == 's') {
			multiplierIntensity *= -1;
		}
		break;
	}
	std::cout << "Intensity: " << multiplierIntensity << " ";
	return 1.0 + multiplierIntensity;
}

std::string TurnWrapper::convertEffectIndexToName(int index) {
	switch (index) {
	case STR_EFFECT_INDEX:
		return "Strength";
		break;
	case DEF_EFFECT_INDEX:
		return "Defense";
		break;
	case SPD_EFFECT_INDEX:
		return "Speed";
		break;
	case EVA_EFFECT_INDEX:
		return "Evasion";
		break;
	case STN_EFFECT_INDEX:
		return "Stun";
		break;
	}
}