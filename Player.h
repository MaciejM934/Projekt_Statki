//
// Created by maciek on 2021-06-16.
//
#ifndef MAIN_CPP_GRACZ_H
#define MAIN_CPP_GRACZ_H
#include "Board.h"
#include "Second_Board.h"
#include "Ship_manager.h"
class Player{
    //Trzeba mu przekazać odpowiedniego ship_menagera
    Second_Board &Enemy_Board;
    Ship_manager &shipManager;
    const std::string name;
public:
    const std::string &getName() const;

public:
    explicit Player(std::string &na,Second_Board &Enemy_Board,Ship_manager &shipManager);
    void Player_set_ship_pos();
    void HUD();
};

#endif //MAIN_CPP_GRACZ_H
