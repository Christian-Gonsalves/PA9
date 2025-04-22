#include "test.hpp"

void Test::testReadEnemyCharacterFromFile(void)
{
	EnemyCharacter test;
	string fileName = "Test_Enemy_1";

	test.readFromFile(fileName);

	cout << "if the next line says \"his is my test catch phrase\" then the test worked: " << endl;
	cout << test.getCatchPhrase();

}
