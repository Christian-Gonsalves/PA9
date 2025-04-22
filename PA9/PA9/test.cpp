#include "test.hpp"

void Test::testReadEnemyCharacterFromFile(void)
{
	EnemyCharacter test;
	string fileName = "Test_Enemy_1.csv";

	test.readFromFile(fileName);

	cout << "if the next line says \"his is my test catch phrase\" then the test worked: " << endl;
	cout << test.getCatchPhrase();

}

void Test::testReadEnemyCharWithMoves(void)
{
	EnemyCharacter test;
	string fileName = "Test_Enemy_2.csv";

	test.readFromFile(fileName);

	cout << "if the next line says \"This was a Test!\" then the test has worked: " << endl;
	cout << test.getMoveSet()[0].getMovePhrase();
}
