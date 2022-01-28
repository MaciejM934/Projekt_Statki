//
// Created by maciek on 2021-06-16.
//
#include "Player.h"



Player::Player(std::string &na,Second_Board &Enemy_Board,Ship_manager &shipManager):
name(na),Enemy_Board(Enemy_Board),shipManager(shipManager)  {}
void Player::Player_set_ship_pos()
{
    std::cout<<"Statki ustawia gracz: "<<name<<std::endl;
    std::cout<<"------------------------------------------"<<std::endl;
    shipManager.set_pos_all_ships();
    std::cout<<"------------------------------------------"<<std::endl;
}
void Player::HUD() {
    std::cout<<"Tura gracza: "<<name<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
    //1.Wyświetlić dostępne ataki
    Enemy_Board.Second_Board_Info();
    //2.Zapytać gdzie chce zaatakować
    Enemy_Board.attack();
    std::cout<<"Koniec tury gracza: "<<name<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
}

const std::string &Player::getName() const {
    return name;
}
