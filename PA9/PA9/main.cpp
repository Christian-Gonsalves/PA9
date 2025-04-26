#include "Screen.hpp"
#include "enemyCharacter.hpp"
#include "GameManage.hpp"
#include "test.hpp"

int main(int argc, const char* argv[])
{
    std::srand(std::time(NULL));
    ifstream funny;
    funny.open("coconut.jpg");
    bool testing = false;

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
