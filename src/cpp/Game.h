//
// Created by jackp on 9/29/2024.
//
#include "Piece.h"
#include "Board.h"
#ifndef GAME_H
#define GAME_H



class Game
{
public:
    Game();
    void PlayGame();
    std::string ConvertToChessNotation(std::pair<int,int> position);
    void GetMoves(Color playerColor);
private:
    Board* gameBoard;

};



#endif //GAME_H
