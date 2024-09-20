#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"


Board::Board()
{
    std::fstream newfile;
    std::cout<<"Creating board"<<std::endl;
    m_board = new std::string*[8];

    for(int i = 0; i < 8; i++)
    {
        m_board[i] = new std::string[8];    // create empty 2d array 8x8
    }

    newfile.open("data/ChessBoard.txt", std::ios::in);
    if(newfile.is_open()) {
        std::cout<<"File opened"<<std::endl;
        for(int f = 0; f < 8; f++)
        {
            for(int r = 0; r < 8; r++) // Occupy the board with the data from the file
            {
                newfile>>m_board[f][r];
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
            std::cout<<m_board[f][r];
            std::cout<<" ";
        }
        std::cout<<8-f<<std::endl;
    }
    std::cout<<"  A  B  C  D  E  F  G  H"<<std::endl;
}

std::string** Board::GetBoard()
{
    return m_board;
}

void Board::SetBoard(std::pair<int, int> local, std::string newPiece)
{
    m_board[local.first][local.second] = newPiece;
}

