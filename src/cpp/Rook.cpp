//
// Created by jackp on 9/28/2024.
//

#include "Rook.h"
#include "Board.h"

Rook::Rook(std::string label, Color color, std::pair<int, int> position) : Piece(label, color, 5, position)
{

}

std::vector<std::pair<int, int>> Rook::GetMoves()
{
    std::vector<std::pair<int,int>> moves;
    int x = GetPosition().second;
    int y = GetPosition().first;

    bool up = true;
    bool down = true;
    bool left = true;
    bool right = true;

    for (int i = 1; i < 8; i++) {
        if (!up && !down && !left && !right) break;

        if (up && y - i >= 0) {
            if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y - i, x))->GetLabel() == "--") {
                moves.emplace_back(y - i, x);
            } else if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y - i, x))->GetColor() != GetColor()) {
                moves.emplace_back(y - i, x);
                up = false;
            } else {
                up = false;
            }
        }
        if (down && y + i < 8) {
            if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y + i, x))->GetLabel() == "--") {
                moves.emplace_back(y + i, x);
            } else if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y + i, x))->GetColor() != GetColor()) {
                moves.emplace_back(y + i, x);
                down = false;
            } else {
                down = false;
            }
        }
        if (left && x - i >= 0) {
            if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y, x - i))->GetLabel() == "--") {
                moves.emplace_back(y, x - i);
            } else if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y, x - i))->GetColor() != GetColor()) {
                moves.emplace_back(y, x - i);
                left = false;
            } else {
                left = false;
            }
        }
        if (right && x + i < 8) {
            if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y, x + i))->GetLabel() == "--") {
                moves.emplace_back(y, x + i);
            } else if (Board::GetInstance().GetPieceAtLocation(std::make_pair(y, x + i))->GetColor() != GetColor()) {
                moves.emplace_back(y, x + i);
                right = false;
            } else {
                right = false;
            }
        }
    }

    return ValidateMoves(moves, GetColor());
}