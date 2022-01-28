//
// Created by maciek on 2021-06-15.
//

#ifndef MAIN_CPP_DESTROYER_H
#define MAIN_CPP_DESTROYER_H
#include "Ship.h"
class Destroyer: public ship
{
public:
    void ship_set_pos();
    explicit Destroyer(Board &Board);
};

#endif //MAIN_CPP_DESTROYER_H
