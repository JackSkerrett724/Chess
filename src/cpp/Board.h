#include <iostream>
#include <string>
#include "Piece.h"

class Board
{
    public:
        Board();
        ~Board();
        void PrintBoard();
        Piece*** GetBoard();
        void SetBoard(std::pair<int,int>, Piece*);
        static Board& GetInstance()
        {
            static Board instance;
            return instance;
        }

    private:
        Piece ***m_board;
};