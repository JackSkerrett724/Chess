#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"

#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Empty.h"




Board::Board() {
    std::fstream newfile;
    std::cout<<"Creating board"<<std::endl;
    m_board = new Piece**[8];

    for(int i = 0; i < 8; i++)
    {
        m_board[i] = new Piece*[8];    // create empty 2d array 8x8
        for (int j = 0; j < 8; j++) {
            m_board[i][j] = nullptr; // Initialize with nullptr
        }
    }

    newfile.open("data/ChessBoard.txt", std::ios::in);
    if(newfile.is_open()) {
        std::cout<<"File opened"<<std::endl;
        for(int f = 0; f < 8; f++)
        {
            for(int r = 0; r < 8; r++) // Occupy the board with the data from the file
            {
                std::string curr;
                newfile>>curr;
                if(curr == "WP")
                {
                    m_board[f][r] = new Pawn(curr, Color::WHITE, std::make_pair(f,r));
                }
                else if(curr == "BP")
                {
                    m_board[f][r] = new Pawn(curr, Color::BLACK, std::make_pair(f,r));
                }
                else if(curr == "WB")
                {
                    m_board[f][r] = new Bishop(curr, Color::WHITE, std::make_pair(f,r));
                }
                else if(curr == "BB")
                {
                    m_board[f][r] = new Bishop(curr, Color::BLACK, std::make_pair(f,r));
                }
                else if (curr == "WN")
                {
                    m_board[f][r] = new Knight(curr, Color::WHITE, std::make_pair(f,r));
                }
                else if (curr == "BN")
                {
                    m_board[f][r] = new Knight(curr, Color::BLACK, std::make_pair(f,r));
                }
                else if (curr == "WR")
                {
                    m_board[f][r] = new Rook(curr, Color::WHITE, std::make_pair(f,r));
                }
                else if (curr == "BR")
                {
                    m_board[f][r] = new Rook(curr, Color::BLACK, std::make_pair(f,r));
                }
                else if (curr == "WQ")
                {
                    m_board[f][r] = new Queen(curr, Color::WHITE, std::make_pair(f,r));
                }
                else if (curr == "BQ")
                {
                    m_board[f][r] = new Queen(curr, Color::BLACK, std::make_pair(f,r));
                }
                else if (curr == "WK")
                {
                    m_board[f][r] = new King(curr, Color::WHITE, std::make_pair(f,r));
                }
                else if (curr == "BK")
                {
                    m_board[f][r] = new King(curr, Color::BLACK, std::make_pair(f,r));
                }
                else
                {
                    m_board[f][r] = new Empty(std::make_pair(f,r));
                }
            }

    }
    std::cout<<"Board created"<<std::endl;
}
    else {
        std::perror("OpenDataFile");
        std::cout<<"Board Creation failed"<<std::endl;
        std::abort();
    }

}

void Board::PrintBoard()
{
    std::cout<<"   A  B  C  D  E  F  G  H"<<std::endl;
    for(int f = 0; f < 8; f++)
    {
        for(int r = 0; r < 8; r++)
        {
            if(r==0){std::cout<<8-f; std::cout<<" ";}
            std::cout<<Board::GetInstance().GetBoard()[f][r]->GetLabel();
            std::cout<<" ";
        }
        std::cout<<8-f<<std::endl;
    }
    std::cout<<"  A  B  C  D  E  F  G  H"<<std::endl;
}

Piece*** Board::GetBoard()
{
    return m_board;
}

void Board::SetBoard(std::pair<int, int> local, Piece *newPiece)
{
    m_board[local.first][local.second] = newPiece;
}


Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete m_board[i][j]; // Delete each Piece object
        }
        delete[] m_board[i]; // Delete each row
    }
    delete[] m_board; // Delete the board
}
