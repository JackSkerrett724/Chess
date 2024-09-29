#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"

#include "Pawn.h"
#include "Bishop.h"




Board::Board()
{
    std::fstream newfile;
    std::cout<<"Creating board"<<std::endl;
    m_board = new Piece**[8];

    for(int i = 0; i < 8; i++)
    {
        m_board[i] = new Piece*[8];    // create empty 2d array 8x8
    }

    newfile.open("data/ChessBoard.txt", std::ios::in);
    if(newfile.is_open()) {
        std::cout<<"File opened"<<std::endl;
        for(int f = 0; f < 8; f++)
        {
            for(int r = 0; r < 8; r++) // Occupy the board with the data from the file
            {
                std::string curr;
                while(newfile >> curr)
                {
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
                    else
                    {
                        m_board[f][r] = new Pawn(curr, Color::WHITE, std::make_pair(f,r));
                    }
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
            std::cout<<m_board[f][r]->GetLabel();
            std::cout<<" ";
        }
        std::cout<<8-f<<std::endl;
    }
    std::cout<<"  A  B  C  D  E  F  G  H"<<std::endl;
}

Piece** Board::GetBoard()
{
    return *m_board;
}

void Board::SetBoard(std::pair<int, int> local, Piece *newPiece)
{
    m_board[local.first][local.second] = newPiece;
}

