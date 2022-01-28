//
// Created by maciek on 2021-06-04.
//
#ifndef STATKI_SHIP_H
#define STATKI_SHIP_H
#include <iostream>
#include <vector>
#include "Board.h"
class ship
{

    int ship_orientation=0;
    int ship_size=0;
    int ship_length=0;
    int ship_height=0;
    int ship_pos_x=0;
    int ship_pos_y=0;
    Board & Board_ref;
public:
    Board &getPlansza() const;

    int getShipOrientation() const;

    void setShipOrientation(int shipOrientation);

    void setShipSize(int shipSize);

    int getShipLength() const;

    void setShipLength(int shipLength);

    int getShipHeight() const;

    void setShipHeight(int shipHeight);

    int getShipPosX() const;

    void setShipPosX(int shipPosX);

    int getShipPosY() const;

    void setShipPosY(int shipPosY);

    int getShipSize() const;

    explicit ship(Board &Board);

    virtual void ship_set_pos();

};
#endif //STATKI_SHIP_H
