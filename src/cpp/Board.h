#include <iostream>
#include <string>

class Board
{
    public:
        Board();
        void PrintBoard();
        std::string** GetBoard();
        void SetBoard(std::pair<int,int>, std::string);
        static Board& GetInstance()
        {
            static Board instance;
            return instance;
        }

    private:
        std::string** m_board;
};