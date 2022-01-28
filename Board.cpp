//
// Created by maciek on 2021-06-04.
//
#include "Board.h"
Board::Board(const int &pl_h, const int &pl_l): board_length(pl_l), board_height(pl_h),attack_pos_y(0),attack_pos_x(0)
{
    board_fill();
}
void Board::board_info() const {
    for(int i=0; i < board_height; ++i)
    {
        for(int j=0; j < board_length; ++j)
        {
            std::cout << Board_size[i][j] << " ";
        }
        std::cout<<std::endl;
    }

}
void Board::board_fill()
{
    Board_size.resize(board_length, std::vector<int>(board_height));
    for(int i=0; i < board_height; ++i)
    {
       for(int j=0; j < board_length; ++j)
       {
           Board_size[i][j]= 0;
       }
    }
}

void Board::board_set_ship_pos(int ship_pos_x, int ship_pos_y, int ship_length, int ship_height ) {
    for (int i = ship_pos_x; i < ship_height + ship_pos_x; ++i) {
        for (int j = ship_pos_y; j < ship_pos_y + ship_length; ++j) {
            if (Board_size[i][j] == 2);//niepotrzebne
            else { Board_size[i][j] = 1; }
        }
    }//Umieszczenie statku
    if (ship_pos_x == 0 && ship_pos_y == 0) {

        for (int i = ship_pos_x; i < ship_pos_x + ship_height + 1; ++i) {
            for (int j = ship_pos_y; j < ship_pos_y + ship_length + 1; ++j) {
                if (Board_size[i][j] == 1);
                else Board_size[i][j] = 2;
            }
        }


    } //Umieszczenie wokół statku innych liczb uniemożliwiających położenie 2 statków obok siebie
    else if (ship_pos_x == 0 && ship_pos_y>0  && ship_pos_y < board_length - 1) {
        for (int i = ship_pos_x; i < ship_pos_x + ship_height + 1; ++i) {
            for (int j = ship_pos_y - 1; j < ship_pos_y + ship_length + 1; ++j) {
                if (Board_size[i][j] == 1);
                else Board_size[i][j] = 2;
            }
        }
    }
    else if (ship_pos_x>0 && ship_pos_x<board_height-1 && ship_pos_y == 0) {
        for (int i = ship_pos_x - 1; i < ship_pos_x + ship_height + 1; ++i) {
            for (int j = ship_pos_y; j < ship_pos_y + ship_length + 1; ++j) {
                if (Board_size[i][j] == 1);
                else Board_size[i][j] = 2;
            }
        }

    }
    else if (ship_pos_x == board_height - 1 && ship_pos_y == board_length - 1) {
        for (int i = ship_pos_x - 1; i < ship_pos_x + ship_height; ++i) {
            for (int j = ship_pos_y - 1; j < ship_pos_y + ship_length; ++j) {
                if (Board_size[i][j] == 1);
                else Board_size[i][j] = 2;
            }
        }
    }
    else if (ship_pos_x == board_height - 1 && ship_pos_y>0 && ship_pos_y < board_length - 1) {
        for (int i = ship_pos_x - 1; i < ship_pos_x + ship_height; ++i) {
            for (int j = ship_pos_y - 1; j < ship_pos_y + ship_length + 1; ++j) {
                if (Board_size[i][j] == 1);
                else Board_size[i][j] = 2;
            }
        }

    }
    else if (ship_pos_x>0 && ship_pos_x< board_height - 1 && ship_pos_y == board_length - 1) {

        for (int i = ship_pos_x - 1; i < ship_pos_x + ship_height + 1; ++i) {
            for (int j = ship_pos_y - 1; j < ship_pos_y + ship_length; ++j) {
                if (Board_size[i][j] == 1);
                else Board_size[i][j] = 2;
            }
        }

     }
    else  if (ship_pos_x == board_height- 1 && ship_pos_y == 0) {
            for (int i = ship_pos_x - 1; i < ship_pos_x + ship_height; ++i) {
                for (int j = ship_pos_y; j < ship_pos_y + ship_length + 1; ++j) {
                    if (Board_size[i][j] == 1);
                    else Board_size[i][j] = 2;
                }
            }
        }
    else if (ship_pos_x == 0 && ship_pos_y == board_length - 1) {
            for (int i = ship_pos_x; i < ship_pos_x + ship_height + 1; ++i) {
                for (int j = ship_pos_y - 1; j < ship_pos_y + ship_length; ++j) {
                    if (Board_size[i][j] == 1);
                    else Board_size[i][j] = 2;
                }
            }

        }
    else if (ship_pos_x != 0 && ship_pos_y != 0 && ship_pos_x != board_height - 1 && ship_pos_y != board_length - 1) {
            for (int i = ship_pos_x - 1; i < ship_pos_x + ship_height + 1; ++i) {
                for (int j = ship_pos_y - 1; j < ship_pos_y + ship_length + 1; ++j) {
                    if (Board_size[i][j] == 1);
                    else Board_size[i][j] = 2;
                }
            }

        }
    }

void Board::attack() {

    //Zapytać gdzie chce zaatakować
    while(true)
    {
        std::cout << "Wybierz pole ktore chcesz atakowac: " << std::endl;
        std::cin >> attack_pos_x >> attack_pos_y;
        //Sprawdzić czy da się tam zaatakować
        if (attack_pos_x <= board_height && attack_pos_y <= board_length && attack_pos_y >= 0 && attack_pos_x >= 0){
            if(Board_size[attack_pos_x - 1][attack_pos_y - 1] == 3)std::cout << "Atakowales tutaj juz wczesniej";
            else break;
        }
        else std::cout<<"Bledne miejsce ataku"<<std::endl;
    }
    Board_size[attack_pos_x - 1][attack_pos_y - 1]=3;

     //Sprawdzić czy już wcześniej tam nie atakował
     //Tak-Wracamy do pytania 2.
     //Nie-wykonujemy ruch?
}

bool Board::is_game_end() {
    for(int i=0;i<board_height-1;++i)
    {
        for(int j=0; j < board_length - 1; ++j)
            if(Board_size[i][j]==1)return false;

    }
    return true;
}

int Board::get_length ()const {return board_length;}
int Board::get_height()const {return board_height;}

const std::vector<std::vector<int>> &Board::getPlanszaSize() const {
    return Board_size;
}

int Board::getAttackPosX() const {
    return attack_pos_x;
}

int Board::getAttackPosY() const {
    return attack_pos_y;
}



