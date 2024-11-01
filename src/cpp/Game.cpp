//
// Created by jackp on 9/29/2024.
//
#include <iostream>
#include "Board.h"
#include <ctime>
#include "Board.h"
#include "Game.h"
#include "Empty.h"
#include "King.h"

#include <algorithm> // for std::count

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

/**
 * Sees if the current player has lost the game
 * @param currPlayer player to check
 * @return True if no legal moves are left, false otherwise
 */
bool Game::IsInCheckmate(Player currPlayer) {
    for (Piece* piece : currPlayer.GetPieces()) {
        std::vector<std::pair<int, int>> originalMoves = piece->GetMoves();
        for (std::pair<int, int> move : originalMoves) {
            // Save the original positions
            std::pair<int, int> originalPosition = piece->GetPosition();
            Piece* targetPiece = gameBoard->GetPieceAtLocation(move);

            // Simulate the move
            gameBoard->SetBoard(move, piece);
            gameBoard->SetBoard(originalPosition, new Empty(originalPosition));
            piece->SetPosition(move);

            // Check if the move puts the player in check
            if (!IsInCheck(currPlayer)) {
                // Restore the original positions
                gameBoard->SetBoard(originalPosition, piece);
                gameBoard->SetBoard(move, targetPiece);
                piece->SetPosition(originalPosition);
                return false; // Found a legal move, not in checkmate
            }

            // Restore the original positions
            gameBoard->SetBoard(originalPosition, piece);
            gameBoard->SetBoard(move, targetPiece);
            piece->SetPosition(originalPosition);
        }
    }
    return true; // No legal moves found, in checkmate
}

/**
 * @brief Check if the current player is in check before they make a move
 *
 * @param currPlayer
 * @return true if the player is in check
 * @return false if the player is not in check
 */
bool Game::IsInCheck(Player currPlayer)
{
    // get the current player's king so we have its location
    King* currKing = nullptr;
    for(Piece* currPiece: currPlayer.GetPieces())
    {
        if(currPiece->GetLabel()[1] == 'K')
        {
            currKing = new King(currPiece->GetLabel(), currPiece->GetColor(), currPiece->GetPosition());
        }
    }
    if(currKing == nullptr)
    {
        std::cout<<"No King found"<<std::endl;
        return false;
    }

    if(currPlayer.GetColor() == Color::WHITE)
    {
        for(Piece* blackPieces: player2.GetPieces())
        {
            for(std::pair<int,int> move: blackPieces->GetMoves())
            {
                if(move == currKing->GetPosition())
                {
                    return true;
                }
            }
        }
    }
    else
    {
        for(Piece* whitePieces: player1.GetPieces())
        {
            for(std::pair<int,int> move: whitePieces->GetMoves())
            {
                if(move == currKing->GetPosition())
                {
                    return true;
                }
            }
        }
    }
    return false;


}


/**
 * @brief Get the moves for the current player
 *
 * @param currPlayer the player to get the moves for
 */
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

    std::vector<std::pair<int, int>> legalMoves = piece->GetMoves();
    for(std::pair<int,int> move: piece->GetMoves())
    {
        std::pair<int,int> originalPosition = piece->GetPosition();
        piece->SetPosition(move);
        gameBoard->SetBoard(move, piece);
        gameBoard->SetBoard(originalPosition, new Empty(piece->GetPosition()));
        if(IsInCheck(currPlayer))
        {
            gameBoard->SetBoard(originalPosition, piece);
            gameBoard->SetBoard(move, new Empty(move));
            legalMoves.erase(std::remove(legalMoves.begin(), legalMoves.end(), move), legalMoves.end());
        }
        else
        {
            gameBoard->SetBoard(piece->GetPosition(), piece);
            gameBoard->SetBoard(move, new Empty(move));
        }
        piece->SetPosition(originalPosition);
    }

    std::cout<<"Possible moves for "<<piece->GetLabel()<<std::endl;
    if(legalMoves.empty())
    {
        std::cout<<"No possible moves"<<std::endl;
        return GetMoves(currPlayer); // recursively call GetMoves until the player selects a piece that can be moved
    }
    for(std::pair<int,int> move: legalMoves)
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


    if(std::count(legalMoves.begin(), legalMoves.end(), position) > 0) // see if the input is in the list of valid moves
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
        if(IsInCheck(currPlayer))
        {
            std::cout<<"This move will put you in check, Invalid Move"<<std::endl;
            gameBoard->SetBoard(piece->GetPosition(), piece);
            gameBoard->SetBoard(position, new Empty(position));
            return GetMoves(currPlayer);
        }
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
    bool gameOver = false;
    while(!gameOver)
    {
        if(IsInCheck(player1))
        {
            if(IsInCheckmate(player1)) {
                std::cout<<"Checkmate"<<std::endl;
                gameOver = true;
                break;
            }
            std::cout<<"Player1 is in Check"<<std::endl;
        }
        GetMoves(player1);

        gameBoard->PrintBoard();
        if(IsInCheck(player2))
        {
            if(IsInCheckmate(player2))
            {
                std::cout<<"Checkmate"<<std::endl;
                gameOver = true;
                break;
            }
            std::cout<<"Player2 is in Check"<<std::endl;
        }
        GetMoves(player2);
        gameBoard->PrintBoard();
    }
    std::cout<<"Game Over"<<std::endl;
}

