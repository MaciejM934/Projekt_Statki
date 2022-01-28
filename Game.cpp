//
// Created by maciek on 2021-06-16.
//
#include "Game.h"
Game::Game(Player &Player_one, Player &Player_two, Board &Player_one_board, Board &Player_two_board):
ref_Player_one(Player_one),ref_Player_two(Player_two),
ref_Player_one_board(Player_one_board),ref_Player_two_board(Player_two_board)
{}
void Game::Play() {
ref_Player_one.Player_set_ship_pos();
ref_Player_two.Player_set_ship_pos();
while(true)
{
    ref_Player_one.HUD();
    if(ref_Player_two_board.is_game_end()==1){
        std::cout << "Wygral gracz: " << ref_Player_one.getName() << std::endl;
        return;
    }
    ref_Player_two.HUD();
    if(ref_Player_one_board.is_game_end()==1){
        std::cout<<"Wygral gracz: "<<ref_Player_two.getName()<<std::endl;
        return;
    }
}
}