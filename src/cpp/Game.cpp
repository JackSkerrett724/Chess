//
// Created by jackp on 9/29/2024.
//

#include <iostream>
#include "Board.h"
#include <ctime>

#include "Game.h"

Game::Game()
{

}

std::string Game::ConvertToChessNotation(std::pair<int,int> position)
{
    std::string chessNotation;
    chessNotation += char(65 + position.second);
    chessNotation += std::to_string(8 - position.first);
    return chessNotation;
}

void Game::PlayGame()
{
    Board* gameBoard = &Board::GetInstance();
    Board::GetInstance().PrintBoard();
    while(true) {
        std::string selection;

        std::cout<<"Enter the piece you want to move (ie A3): ";
        std::cin>>selection;

        std::pair<int,int> position;
        position.second = abs(65 - int(selection[0])); // ASCII Yay!
        position.first = 8 - (selection[1] - '0');

        Piece* piece = gameBoard->GetPieceAtLocation(position);

        std::cout<<"Possible moves for "<<piece->GetLabel()<<std::endl;
        if(piece->GetMoves().empty())
        {
            std::cout<<"No possible moves"<<std::endl;
        }
        else
        {
            for(std::pair<int,int> move: piece->GetMoves())
            {
                std::cout<<ConvertToChessNotation(move)<<",";
            }
        }

        std::cout<<std::endl;
    }
}

