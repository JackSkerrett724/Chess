#include <iostream>

#include "Game.h"

int main()
{
    Board::GetInstance().PrintBoard();
    Game *game = new Game();
    game->PlayGame();
    return 0;
}
