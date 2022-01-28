//
// Created by maciek on 2021-06-16.
//

#ifndef MAIN_CPP_SHIP_MENAGER_H
#define MAIN_CPP_SHIP_MENAGER_H
#include "Ship.h"
#include "battlecruiser.h"
#include "Destroyer.h"
#include "Board.h"
class Ship_manager{
    //Dostaje referencje na plansze na której gracz stawia swoje statki
    std::vector<ship>ships;
    std::vector<battlecruiser>battlecruisers;
    std::vector<Destroyer>Destroyers;
    Board &Board_ref;
    int ships_1;
    int ships_2;
    int ships_3;
public:
    explicit Ship_manager(Board &Board, int shi, int battl, int Destr);
    void set_pos_all_ships();
};
#endif //MAIN_CPP_SHIP_MENAGER_H
