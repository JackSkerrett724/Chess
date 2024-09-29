//
// Created by jackp on 9/28/2024.
//

#include "Empty.h"


Empty::Empty(std::pair<int,int> position) : Piece("--", NONE, 0, position)
{

}

std::vector<std::pair<int, int> > Empty::GetMoves()
{
    return std::vector<std::pair<int,int>>();
}