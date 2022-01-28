//
// Created by maciek on 2021-06-16.
//
#include "Second_Board.h"
Second_Board::Second_Board(Board &Board): Board_ref(Board) {Second_Board::Fill();}

void Second_Board::Fill()
{
Second_Board_size.resize(Board_ref.get_length(), std::vector<int>(Board_ref.get_height()));
    for(int i=0; i < Board_ref.get_height(); ++i)
    {
        for(int j=0; j < Board_ref.get_length(); ++j)
        {
            Second_Board_size[i][j]= 0;
        }
    }
}
void Second_Board::attack()
{
 Board_ref.attack();
 Second_Board_size[Board_ref.getAttackPosX()-1][Board_ref.getAttackPosY()-1]=3;
}
void Second_Board::Second_Board_Info() const {
    for(int i=0; i < Board_ref.get_height(); ++i)
    {
        for(int j=0; j < Board_ref.get_length(); ++j)
        {
            std::cout << Second_Board_size[i][j] << "  ";
        }
        std::cout<<std::endl;
    }

}