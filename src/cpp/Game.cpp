//
// Created by jackp on 9/29/2024.
//
#include <iostream>
#include "Board.h"
#include <ctime>
#include "Board.h"
#include "Game.h"

#include "Player.h"

Game::Game()
{
    Player player1 = Player("Player1", Color::WHITE);
    Player player2 = Player("Player2", Color::BLACK);
    gameBoard = &Board::GetInstance();
}

std::string Game::ConvertToChessNotation(std::pair<int,int> position)
{
    std::string chessNotation;
    chessNotation += char(65 + position.second);
    chessNotation += std::to_string(8 - position.first);
    return chessNotation;
}


void Game::GetMoves(Color playerColor)
{
    std::string selection; // initialize selection
    std::cout<<playerColor<<" Enter the piece you want to move (ie A3): "; // prompt user
    std::cin>>selection; // get user input
    std::pair<int,int> position; // initialize position to be filled in
    position.second = abs(65 - int(selection[0])); // ASCII Yay! A = 65, B = 66, etc.
    position.first = 8 - (selection[1] - '0');
    Piece* piece = gameBoard->GetPieceAtLocation(position); // get the piece at the location provided

    if(piece->GetColor() != playerColor)
    {
        std::cout<<"You can't move that piece"<<std::endl;
        return GetMoves(playerColor); // recursively call GetMoves until the player selects a piece of their color
    }

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

void Game::PlayGame()
{
    while(true)
    {
        GetMoves(Color::WHITE);
        GetMoves(Color::BLACK);
    }
}

