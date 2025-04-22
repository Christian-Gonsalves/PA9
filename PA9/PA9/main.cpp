#include "Screen.hpp"
#include "enemyCharacter.hpp"
#include "GameManage.hpp"

int main(int argc, const char* argv[])
{
    std::srand(std::time(NULL));
    GameManage game;
    game.run();
    return 0;
}
