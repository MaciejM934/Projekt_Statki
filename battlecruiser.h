//
// Created by maciek on 2021-06-15.
//

#ifndef MAIN_CPP_BATTLECRUISER_H
#define MAIN_CPP_BATTLECRUISER_H
#include "Ship.h"
class battlecruiser: public ship
{
public:
    void ship_set_pos();
    explicit battlecruiser(Board &Board);
};


#endif //MAIN_CPP_BATTLECRUISER_H
