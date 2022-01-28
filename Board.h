//
// Created by maciek on 2021-06-04.
//
#ifndef STATKI_PLANSZA_H
#define STATKI_PLANSZA_H
#include <iostream>
#include <vector>
class Board
{
    int board_height;
    int board_length;
    int attack_pos_x;
    int attack_pos_y;
    std::vector<std::vector<int>> Board_size;
public:
    int getAttackPosX() const;

    int getAttackPosY() const;

    const std::vector<std::vector<int>> &getPlanszaSize() const;

    Board(const int &pl_h, const int &pl_l);

    int get_height() const;

    int get_length ()const;

    void board_fill();

    void board_info()const;

    void attack();

    bool is_game_end(); //Zwraca 1 gdy gra się skończy

    void board_set_ship_pos(int ship_pos_x, int ship_pos_y, int ship_length, int ship_height );



};
#endif //STATKI_PLANSZA_H
