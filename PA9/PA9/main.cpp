<<<<<<< HEAD
#include <iostream>
#include "Screen.hpp"
#include "enemyCharacter.hpp"



int main() {
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");
	Screen s;


	s.run(window);
	return 0;
}
=======
#include "Screen.hpp"
#include "enemyCharacter.hpp"
#include "GameManage.hpp"
#include "test.hpp"

int main(int argc, const char* argv[])
{
    Test t;
    t.testReadEnemyCharacterFromFile();
    t.testReadEnemyCharWithMoves();
    t.testChooseEnemyMove();




    std::srand(std::time(NULL));
    GameManage game;
    game.run();
    return 0;
}
>>>>>>> andres-2
