#pragma once
#include "test.hpp"


void Test::testReadEnemyCharacterFromFile(void)
{
	cout << "Begin Test 1" << endl << endl;

	EnemyCharacter test;
	string fileName = "Test_Enemy_1.csv";

	test.readFromFile(fileName);
	cout << "This test will read in an enemy character from a file with no moves" << endl << endl;
	cout << "If the next line says \"This is my test catch phrase\" then the test worked: " << endl;
	cout << test.getCatchPhrase() << endl;
	cout << endl << "End of Test 1" << endl << endl;

}

void Test::testReadEnemyCharWithMoves(void)
{
	cout << "Begin Test 2" << endl << endl;

	EnemyCharacter test;
	string fileName = "Test_Enemy_2.csv";

	test.readFromFile(fileName);

	

	cout << "This test will read in an enemy character from a file with 3 moves" << endl << endl;
	cout << "If the next line says \"This was a Test!\" then the test has worked: " << endl;
	cout << test.getMoveSet()[0].getMovePhrase() << endl;
	cout << endl << "End of Test 2" << endl << endl;

}

void Test::testChooseEnemyMove(void)
{

	cout << "Begin Test 3" << endl << endl;

	EnemyCharacter test1;
	Character test2;
	string fileName = "Test_Enemy_2.csv";
	Move* chosenMove;

	test1.readFromFile(fileName);

	//cout << test1.getMoveSet()[0].getMoveName() << endl;

	TurnWrapper turn(test1, test2);

	cout << "This test will loop through an enemy with three moves, two of the moves have the same type" << endl;
	cout << "and they should not repeat" << endl << endl;

	for (int i = 0; i < 20; i ++){
		chosenMove = turn.chooseEnemyMove();
		cout << "The chosen move was: " << chosenMove->getMoveName() << " with type: " << chosenMove->getMoveType() << endl;
	} 

	cout << endl << "End of Test 3" << endl << endl;
}

void Test::testPlayMove(void)
{
	cout << "Begin Test 4" << endl << endl;

	EnemyCharacter attacker, defender;
	string attackerFile = "Test_Enemy_2.csv", defenderFile = "Test_Enemy_1.csv";

	attacker.readFromFile(attackerFile);
	defender.readFromFile(defenderFile);
	

	TurnWrapper turn(attacker, defender);
	cout << "This test will check to see if a hit is succesfull or not on an emeny, it will also print the moves catch phrase" << endl;
	cout << "it will also check to see how much damage the move is supposed to do and if the damage is properly dealt" << endl;

	cout << endl << defender.getName() << "'s initial health is: " << defender.getCurrentHealth() << endl;

	Move* choosenMove = turn.chooseEnemyMove();

	cout << endl << "The attackers chosen move was: " << choosenMove->getMoveName() << " with a power of: " << choosenMove->getPower() << endl;
	cout << "The attackers base attack is: " << attacker.getAttack() << endl;
	if (attacker.getStatusEffectTurns(STN_EFFECT_INDEX) > 0) { // Stunned
		return;
	}


	// Move Dialogue
	string playedMovePhrase = choosenMove->getMovePhrase();

	// Does player hit attack?
	double totalMoveAccuracy = attacker.getAccuracy() * choosenMove->getAccuracy();
	double totalRecipientEvasion = defender.getAgility() * (1 + .25 * (defender.getStatusEffectStrength(SPD_EFFECT_INDEX))) * (1 + .25 * (defender.getStatusEffectStrength(EVA_EFFECT_INDEX)));

	if ((std::rand() % (10000 - 1 + 1) + 1) >= 10000 - ((int)10000 * totalMoveAccuracy / totalRecipientEvasion)) { // Essentially a random number with (accuracy / evasion)% chance of occuring accurate to 3 decimal points 
		// Damage Calculations
		int totalDamage = attacker.getAttack() * (1 + .25 * (attacker.getStatusEffectStrength(STR_EFFECT_INDEX))) * choosenMove->getPower();
		totalDamage -= defender.getDefense() * (1 + .25 * (defender.getStatusEffectStrength(DEF_EFFECT_INDEX)));
		defender.setCurrentHealth(defender.getCurrentHealth() - totalDamage);

		// Status Effect (Currently completely overwrites a given status effect type with the new strenth and duration. This means if it was previously a strength of -2 and then a strength of 1 was applied, the final status effect would be 1)
		for (int i = 0; i < 10; i += 2) {
			if (choosenMove->getEffectTurns(i) != 0) {
				defender.setStatusEffect(i, choosenMove->getEffectTurns(i), choosenMove->getEffectStrength(i));
			}
		}
	}
	else {
		cout << "The attack missed" << endl;
	}

	choosenMove->setCurMoveCount(choosenMove->getCurMoveCount() - 1);




	cout << endl << defender.getName() << "'s new health is: " << defender.getCurrentHealth() << endl;

	cout << endl << "End of Test 4" << endl << endl;

}

void Test::testHitEvasionLogic(void)
{
	cout << "Begin Test 5" << endl << endl;


	EnemyCharacter attacker, defender;
	string attackerFile = "Test_Enemy_2.csv", defenderFile = "Test_Enemy_1.csv";

	attacker.readFromFile(attackerFile);
	defender.readFromFile(defenderFile);

	cout << "This test will check the hit evasion logic used in the \"play Move\" function. This will be done by" << endl;
	cout << "creating a copy of the logic and looping though the logic 1000 times and will record the amount of hits and misses" << endl;

	cout << endl << "The attackers accuracy stat is: " << attacker.getAccuracy() << endl;
	cout << "The defenders evasion stat is: " << defender.getAgility() << endl;


	TurnWrapper turn(attacker, defender);

	int misses = 0, hits = 0;



	for (int i = 0; i < 1000; i++) {

		Move* choosenMove = turn.chooseEnemyMove();

		double totalMoveAccuracy = attacker.getAccuracy() * choosenMove->getAccuracy();
		double totalRecipientEvasion = defender.getAgility() * (1 + .25 * (defender.getStatusEffectStrength(SPD_EFFECT_INDEX))) * (1 + .25 * (defender.getStatusEffectStrength(EVA_EFFECT_INDEX)));

		if ((std::rand() % (10000 - 1 + 1) + 1) >= 10000 - ((int)10000 * totalMoveAccuracy / totalRecipientEvasion)) { // Essentially a random number with (accuracy / evasion)% chance of occuring accurate to 3 decimal points 
			// Damage Calculations
			int totalDamage = attacker.getAttack() * (1 + .25 * (attacker.getStatusEffectStrength(STR_EFFECT_INDEX))) * choosenMove->getPower();
			totalDamage -= defender.getDefense() * (1 + .25 * (defender.getStatusEffectStrength(DEF_EFFECT_INDEX)));
			defender.setCurrentHealth(defender.getCurrentHealth() - totalDamage);

			// Status Effect (Currently completely overwrites a given status effect type with the new strenth and duration. This means if it was previously a strength of -2 and then a strength of 1 was applied, the final status effect would be 1)
			for (int i = 0; i < 10; i += 2) {
				if (choosenMove->getEffectTurns(i) != 0) {
					defender.setStatusEffect(i, choosenMove->getEffectTurns(i), choosenMove->getEffectStrength(i));
				}
			}
			hits++;
		}
		else {
			misses++;
		}

	}
	cout << endl << "Total hits: " << hits << " Total misses: " << misses << endl;

	cout << endl << "End of Test 5" << endl << endl;

}
