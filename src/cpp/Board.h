#include <iostream>
#include <string>
#include "Piece.h"

class Board
{
    public:
        Board();
        ~Board();
        void PrintBoard();

        Board GetBoard();
        Piece* GetPieceAtLocation(std::pair<int,int>);
        void SetBoard(std::pair<int,int>, Piece*);
        static Board& GetInstance()
        {
            static Board instance;
            return instance;
        }

    private:
        Piece ***m_board;
};