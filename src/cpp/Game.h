//
// Created by jackp on 9/29/2024.
//
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#ifndef GAME_H
#define GAME_H



class Game
{
public:
    Game();
    void PlayGame();
    std::string ConvertToChessNotation(std::pair<int,int> position);
    void GetMoves(Player currPlayer);
    bool IsInCheck(Player currPlayer);
    bool IsInCheckmate(Player currPlayer);
private:
    Board* gameBoard;
    Player player1;
    Player player2;

};



#endif //GAME_H
