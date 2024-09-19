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
            for(int r = 0; r < 8; r++)
            {
                newfile>>m_board[f][r];
            }
        }
        std::cout<<"Board created"<<std::endl;
    }
    else {std::perror("OpenDataFile");}

}

void Board::PrintBoard()
{
    std::cout<<"Printing board"<<std::endl;
    for(int f = 0; f < 8; f++)
    {
        for(int r = 0; r < 8; r++)
        {
            std::cout<<m_board[f][r];
        }
        std::cout<<std::endl;
    }
    std::cout<<"Board printed"<<std::endl;
}

std::string** Board::GetBoard()
{
    return m_board;
}