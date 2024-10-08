//
// Created by jackp on 9/29/2024.
//
#include <iostream>
#include "Board.h"
#include <ctime>
#include "Board.h"
#include "Game.h"
#include "Empty.h"

#include <algorithm>

#include "Player.h"

Game::Game() : player1(Player::GetPlayer1()), player2(Player::GetPlayer2())
{
    gameBoard = &Board::GetInstance();
}

std::string Game::ConvertToChessNotation(std::pair<int,int> position)
{
    std::string chessNotation;
    chessNotation += char(65 + position.second);
    chessNotation += std::to_string(8 - position.first);
    return chessNotation;
}


void Game::GetMoves(Player currPlayer)
{
    std::string selection; // initialize selection
    std::cout<<currPlayer.GetName()<<" Enter the piece you want to move (ie A3): "; // prompt user
    std::cin>>selection; // get user input
    std::pair<int,int> position; // initialize position to be filled in
    position.second = abs(65 - int(selection[0])); // ASCII Yay! A = 65, B = 66, etc.
    position.first = 8 - (selection[1] - '0');
    Piece* piece = gameBoard->GetPieceAtLocation(position); // get the piece at the location provided

    if(piece->GetColor() != currPlayer.GetColor())
    {
        std::cout<<"You can't move that piece"<<std::endl;
        return GetMoves(currPlayer); // recursively call GetMoves until the player selects a piece of their color
    }

    std::cout<<"Possible moves for "<<piece->GetLabel()<<std::endl;
    if(piece->GetMoves().empty())
    {
        std::cout<<"No possible moves"<<std::endl;
        return GetMoves(currPlayer); // recursively call GetMoves until the player selects a piece that can be moved
    }
    for(std::pair<int,int> move: piece->GetMoves())
    {
        std::cout<<ConvertToChessNotation(move)<<",";
    }
    std::cout<<std::endl;;
    std::cout<<currPlayer.GetName()<<" Enter where you'd like to move the "<<piece->GetLabel()<<" to (c to cancel): "; // prompt user
    std::cin>>selection; // get user input
    if(selection == "c")
    {
        return GetMoves(currPlayer); // go back to the start
    }
    position.second = abs(65 - int(selection[0])); // ASCII Yay! A = 65, B = 66, etc.
    position.first = 8 - (selection[1] - '0');


    std::vector<std::pair<int,int>> validMoves = piece->GetMoves();
    if(std::count(validMoves.begin(), validMoves.end(), position) > 0) // see if the input is in the list of valid moves
    {
        if(gameBoard->GetPieceAtLocation(position)->GetLabel() != "--") // get rid of pieces from the other player, will help later i think
        {
            if(currPlayer.GetColor() == Color::WHITE)
            {
                player2.RemovePiece(gameBoard->GetPieceAtLocation(position));
            }
            else
            {
                player1.RemovePiece(gameBoard->GetPieceAtLocation(position));
            }
        }
        gameBoard->SetBoard(position, piece);
        gameBoard->SetBoard(piece->GetPosition(), new Empty(piece->GetPosition()));
        piece->SetPosition(position);
    }
    else
    {
        std::cout<<"Invalid Move"<<std::endl;
        return GetMoves(currPlayer);
    }

    std::cout<<std::endl;
}

void Game::PlayGame()
{
    while(true)
    {
        GetMoves(player1);
        gameBoard->PrintBoard();
        GetMoves(player2);
        gameBoard->PrintBoard();
    }
}

