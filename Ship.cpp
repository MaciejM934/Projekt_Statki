//
// Created by maciek on 2021-06-04.
//
#include "Ship.h"
ship::ship(Board &Board): Board_ref(Board) {
}

void ship::ship_set_pos()
{
    //pytam o 3 rzeczy i switch_loop tego jestem w stanie określić położenie statku
    setShipSize(1);


    int flat=1;
    int vertical=0;
    int first_while_loop=0;
    while (first_while_loop<1) {
    std::cout<<"Jak chcesz umiescic statek: "<<std::endl;
    std::cout<<"Poziomo[1]"<<std::endl;
    std::cout<<"Pionowo[2]\n"<<std::endl;
    int switch_loop=0;
    std::cin>>switch_loop;

        switch (switch_loop) {
            case 1:
                setShipOrientation(flat);
                first_while_loop=1;//0 oznacza pion
                break;
            case 2:
                setShipOrientation(vertical);
                first_while_loop=1;// 1 oznacza poziom
                break;
            default:
                std::cout << "Niepoprawna orientacja \n";

        }
    }
    int while_loop=0;
    while(while_loop < 1){
        std::cout<<"Podaj wspolrzedne poczatku: \n";
        std::cin>>ship_pos_x>>ship_pos_y;
        ship_pos_x=ship_pos_x-1;
        ship_pos_y=ship_pos_y-1;

        if (ship_orientation==flat){
            if(ship_pos_y+ship_size <= Board_ref.get_length()){
                setShipLength(ship_size);
                setShipHeight(1);
                while_loop=1;
            }
            else std::cout<<"Bledne polozenie poczatkowe. \n"<<std::endl;
        }//sprawdzam czy statek mieści się na planszy

        if (ship_orientation==vertical){
            if(ship_pos_x+ship_size <= Board_ref.get_height()){
                setShipHeight(ship_size);// ustawienie długości i wysokości statku
                setShipLength(1);
                while_loop=1;
            }
            else std::cout<<"Bledne polozenie poczatkowe"<<std::endl;
        }//sprawdzam czy statek mieści się na planszy

        int for_loop=0;

        for(int i=ship_pos_x;i<ship_height+ship_pos_x;++i){
            for(int j=ship_pos_y;j<ship_pos_y+ship_length;++j)
            {
                if(Board_ref.getPlanszaSize()[i][j] != 0)for_loop=1;
            }
        }

        if(for_loop!=0) {
            std::cout << "Statki nie moga na siebie nachodzic ani byc obok siebie!" << std::endl;
            while_loop=0;
        }

    }
    Board_ref.board_set_ship_pos(getShipPosX(), getShipPosY(),
                                 getShipLength(), getShipHeight());
}


void ship::setShipPosX(int shipPosX) {
    ship_pos_x = shipPosX;
}
void ship::setShipPosY(int shipPosY) {
    ship_pos_y = shipPosY;
}


void ship::setShipHeight(int shipHeight) {
    ship_height = shipHeight;
}

void ship::setShipLength(int shipLength) {
    ship_length = shipLength;
}

void ship::setShipSize(int shipSize) {
    ship_size = shipSize;
}

void ship::setShipOrientation(int shipOrientation) {
    ship_orientation = shipOrientation;
}

int ship::getShipOrientation() const {
    return ship_orientation;
}

int ship::getShipLength() const {
    return ship_length;
}

int ship::getShipHeight() const {
    return ship_height;
}

int ship::getShipPosX() const {
    return ship_pos_x;
}

int ship::getShipPosY() const {
    return ship_pos_y;
}

int ship::getShipSize() const {
    return ship_size;
}

Board &ship::getPlansza() const {
    return Board_ref;
}




