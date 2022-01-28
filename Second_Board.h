//
// Created by maciek on 2021-06-16.
//

#ifndef MAIN_CPP_SECOND_BOARD_H
#define MAIN_CPP_SECOND_BOARD_H
#include "Board.h"
class Second_Board{
    //dostaje referencje na planszę przeciwnika
    std::vector<std::vector<int>> Second_Board_size;
    Board & Board_ref;
public:
    explicit Second_Board(Board &Board);
    void attack();
    void Fill();
    void Second_Board_Info() const;
};

#endif //MAIN_CPP_SECOND_BOARD_H
