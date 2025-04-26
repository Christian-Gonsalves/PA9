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
    std::srand(std::time(NULL));
    ifstream funny;
    funny.open("coconut.jpg");

    bool testing = false;   //change this to true to see test output in terminal

    if (funny.is_open()) {
        if (testing) {
            Test t;
            t.testReadEnemyCharacterFromFile();
            t.testReadEnemyCharWithMoves();
            t.testChooseEnemyMove();
            t.testPlayMove();
            t.testHitEvasionLogic();
        }

        GameManage game;
        game.run();
        return 0;
    }
    return 0;

}
>>>>>>> andres-2
