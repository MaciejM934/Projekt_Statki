//
// Created by maciek on 2021-06-16.
//

#ifndef MAIN_CPP_GRA_H
#define MAIN_CPP_GRA_H
#include "Player.h"
#include "Board.h"
class Game{
    Player &ref_Player_one;
    Player &ref_Player_two;
    Board &ref_Player_one_board;
    Board &ref_Player_two_board;
public:
    Game(Player &Player_one,Player &Player_two,Board &Player_one_board, Board &Player_two_board);
    void Play();
};
#endif //MAIN_CPP_GRA_H
