#include <iostream>
#include <string>

class Board
{
    public:
        Board();
        void PrintBoard();
        std::string** GetBoard();

    private:
        std::string** m_board;
};