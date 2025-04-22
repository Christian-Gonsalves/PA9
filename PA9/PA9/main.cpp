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
