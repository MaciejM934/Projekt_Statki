//
// Created by maciek on 2021-06-16.
//
#include "Ship_manager.h"
Ship_manager::Ship_manager(Board &Board, int shi, int battl, int Destr):
Board_ref(Board), ships_1(shi),ships_2(battl),ships_3(Destr)  {

    for(int i=0;i<ships_1;++i)
    {
        ships.push_back(ship(Board_ref));
    }
    for(int i=0;i<ships_2;++i)
    {
        battlecruisers.push_back(battlecruiser(Board_ref));
    }
    for(int i=0;i<ships_3;++i)
    {
        Destroyers.push_back(Destroyer(Board_ref));
    }
}

void Ship_manager::set_pos_all_ships() {
    for(auto & ship : ships)
    {
        Board_ref.board_info();
        ship.ship_set_pos();
    }
    for(auto & battlecruiser: battlecruisers)
    {
        Board_ref.board_info();
        battlecruiser.ship_set_pos();
    }
    for(auto & Destroyer: Destroyers)
    {
        Board_ref.board_info();
        Destroyer.ship_set_pos();
    }
}
