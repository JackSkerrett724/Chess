//
// Created by jackp on 9/29/2024.
//

#ifndef GAME_H
#define GAME_H



class Game
{
public:
    Game();
    void PlayGame();
    std::string ConvertToChessNotation(std::pair<int,int> position);

};



#endif //GAME_H
