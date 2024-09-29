//
// Created by jackp on 9/28/2024.
//

#include "Queen.h"

#include "Bishop.h"
#include "Rook.h"


Queen::Queen(std::string label, Color color, std::pair<int, int> position) : Piece(label, color, 9, position)
{

}

std::vector<std::pair<int, int> > Queen::GetMoves()
{
    std::vector<std::pair<int,int>> moves;
    int x = GetPosition().second;
    int y = GetPosition().first;

    // If we think about it, a queen is just a rook and a bishop combined,
    // so we can just create a rook and a bishop and get their moves and combine them
    // into the queen's moves
    // this saves a lot of code duplication
    Rook rook("Rook", GetColor(), GetPosition());
    Bishop bishop("Bishop", GetColor(), GetPosition());
    moves = rook.GetMoves();
    moves.insert(moves.end(), bishop.GetMoves().begin(), bishop.GetMoves().end());

    return ValidateMoves(moves, GetColor()); // This is probably not necessary, but it's good to have

}
