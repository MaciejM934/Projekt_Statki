
#include "Board.h"
#include "Second_Board.h"
#include "Ship.h"
#include "Ship_manager.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

int main() {


    std::string Player_one_name="Maciek";
    std::string Player_two_name="Ala";
    int Board_size=10;
    int Ships_1=1;
    int Ships_2=1;
    int Ships_3=1;
    Board Player_one_board(Board_size, Board_size);
    Board Player_two_board(Board_size, Board_size);
    Second_Board Player_one_view_board(Player_two_board);
    Second_Board Player_two_view_board(Player_one_board);
    Ship_manager Player_one_shipManager(Player_one_board, Ships_1, Ships_2, Ships_3);
    Ship_manager Player_two_shipManager(Player_two_board, Ships_1, Ships_2, Ships_3);
    Player Player_one(Player_one_name, Player_two_view_board, Player_one_shipManager);
    Player Player_two(Player_two_name, Player_one_view_board, Player_two_shipManager);
    Game Start(Player_one, Player_two, Player_one_board, Player_two_board);
    Start.Play();




//0.Po podaniu wielkości planszy mogę stworzyć 4 takie plansze na 2 gracze będą ustawiali statki a na 2 będą atakowali
//1. Na mapie 1 oznacza statek;
//2. Na mapie 2 oznacza pole które nie może być zajęte przez inny statek
//3. Na mapie 3 oznacza miejsce w które ktoś zatakował

}
