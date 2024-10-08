//
// Created by jackp on 10/1/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Piece.h"
#include <vector>

class Player
{
public:
    Player(std::string name, Color color);
    std::string GetName();
    Color GetColor();
    void SetColor(Color color);
    void SetName(std::string name);
    void AddPiece(Piece *piece);
    void RemovePiece(Piece *piece);
    std::vector<Piece> GetPieces();
    static Player& GetPlayer1() {
        static Player* player1 = new Player("Player 1", Color::WHITE);
        return *player1;
    }
    static Player& GetPlayer2() {
        static Player* player2 = new Player("Player 2", Color::BLACK);
        return *player2;
    }
private:
    std::string m_name;
    Color m_color;
    std::vector<Piece*> m_pieces;
};



#endif //PLAYER_H
