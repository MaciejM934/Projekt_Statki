//
// Created by maciek on 2021-06-15.
//
#include "battlecruiser.h"
battlecruiser::battlecruiser(Board &Board) : ship(Board) {}
void battlecruiser::ship_set_pos()
{
    //pytam o 3 rzeczy i switch_loop tego jestem w stanie określić położenie statku
    setShipSize(2);


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
                first_while_loop = 1;//0 oznacza pion
                break;
            case 2:
                setShipOrientation(vertical);
                first_while_loop = 1;// 1 oznacza poziom
                break;
            default:
                std::cout << "Niepoprawna orientacja \n";

        }
    }
    int x,y;
    int while_loop=0;
    while(while_loop < 1){
        std::cout<<"Podaj wspolrzedne poczatku: \n";
        std::cin>>x>>y;
        x=x-1;
        y=y-1;
        setShipPosY(y);
        setShipPosX(x);

        if (getShipOrientation()==flat){
            if(getShipPosY()+getShipSize()<= getPlansza().get_length()){
                setShipLength(getShipSize());
                setShipHeight(1);
                while_loop=1;
            }
            else std::cout<<"Bledne polozenie poczatkowe. \n"<<std::endl;
        }//sprawdzam czy statek mieści się na planszy

        if (getShipOrientation()==vertical){
            if(getShipPosX()+getShipSize()<=getPlansza().get_height()){
                setShipHeight(getShipSize());// ustawienie długości i wysokości statku
                setShipLength(1);
                while_loop=1;
            }
            else std::cout<<"Bledne polozenie poczatkowe"<<std::endl;
        }//sprawdzam czy statek mieści się na planszy

        int for_loop=0;

        for(int i=getShipPosX();i<getShipHeight()+getShipPosX();++i){
            for(int j=getShipPosY();j<getShipPosY()+getShipLength();++j)
            {
                if(getPlansza().getPlanszaSize()[i][j]!=0)for_loop=1;
            }
        }

        if(for_loop!=0) {
            std::cout << "Statki nie moga na siebie nachodzic ani byc obok siebie!" << std::endl;
            while_loop=0;
        }

    }
    getPlansza().board_set_ship_pos(getShipPosX(), getShipPosY(),
                               getShipLength(), getShipHeight());
}

