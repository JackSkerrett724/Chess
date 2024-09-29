#include <iostream>

#include "Board.h"

#include <cmath>

int main()
{
    Board* gameBoard = &Board::GetInstance();


    Board::GetInstance().PrintBoard();
    while(true) {
        std::string selection;

        std::cout<<"Enter the piece you want to move (ie A3): ";
        std::cin>>selection;

        std::pair<int,int> position;
        position.second = abs(65 - int(selection[0]));
        position.first = 8 - (selection[1] - '0');

        Piece* piece = gameBoard->GetPieceAtLocation(position);

        std::cout<<"Possible moves for "<<piece->GetLabel()<<std::endl;
        for(std::pair<int,int> move: piece->GetMoves())
        {
            std::cout<<move.first<<","<<move.second<<std::endl;
        }
    }

    return 0;
}
