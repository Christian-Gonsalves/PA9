#pragma once
#include "test.hpp"


void Test::testReadEnemyCharacterFromFile(void)
{
	EnemyCharacter test;
	string fileName = "Test_Enemy_1.csv";

	test.readFromFile(fileName);

	cout << "if the next line says \"This is my test catch phrase\" then the test worked: " << endl;
	cout << test.getCatchPhrase() << endl;
	cout << "End of test 1" << endl << endl;

}

void Test::testReadEnemyCharWithMoves(void)
{
	EnemyCharacter test;
	string fileName = "Test_Enemy_2.csv";

	test.readFromFile(fileName);

	cout << "if the next line says \"This was a Test!\" then the test has worked: " << endl;
	cout << test.getMoveSet()[0].getMovePhrase();
	cout << "End of test 2" << endl << endl;

}

void Test::testChooseEnemyMove(void)
{
	EnemyCharacter test1;
	Character test2;
	string fileName = "Test_Enemy_2.csv";
	Move *chosenMove;

	test1.readFromFile(fileName);

	cout << test1.getMoveSet()[0].getMoveName() << endl;

	TurnWrapper turn(test1, test2);

	cout << "This test will loop through an enemy with three moves, two of the moves have the same type" << endl;
	cout << "and they should not repeat, there will also be a move count which should drop as the moves get used" << endl;

	do {
		chosenMove = turn.chooseEnemyMove();
		cout << "The chosen move was: " << chosenMove->getMoveName() << " with type: ";
		cout << chosenMove->getMoveType() << " and with " << chosenMove->getCurMoveCount() << " moves left" << endl;
	} while (chosenMove != nullptr);





	




	

}
