#include <iostream>
#include <windows.h>
//#include "interfaces/MainMenu.h"
#include "services/Input.h"

#include "services/Storage.h"
#include "immovables/piece/Piece.h"
#include "immovables/piece/House.h"
#include "immovables/piece/Empty.h"
#include "immovables/flat/Flat.h"
#include "immovables/parking/Parking.h"
#include "immovables/commercial/Commercial.h"

static unsigned int id = 0;
using namespace std;

int main() {
    setlocale(LC_ALL,"ru");
    SetConsoleOutputCP(CP_UTF8);

    Input in;

    /// -----------------------------

//    Piece piece(id++, "+375293332255", "emsobak@mail.ru", 9800, 102000, "обл. Минск, п. Стрипиздикова, ул. Ленина, 7", true, true, true, true);
//    piece.printInfo();

    House house(id++, "+375293332255", "emsobak@mail.ru", 24500, 140200, "обл. Минск, г. Натальевск, ул. Ленина, 12", false, false, true, true, 2, 11, 8);
//    house.printInfo();

    Empty em(id++, "+375293332255", "emsobak@mail.ru", 9800, 102000, "обл. Минск, п. Стрипиздикова, ул. Ленина, 7", true, true, false, true, true, false);
//    em.printInfo();

    Flat flat(id++, "+375293332255", "emsobak@mail.ru", 12300, 320, "г. Минск, ул. Ленина, д. 34/2, кв. 16", false, 4, 3, true);
//    flat.printInfo();

    Parking parking(id++, "+375293332255", "emsobak@mail.ru", 12300, 320, "г. Минск, ул. Ленина, д. 34/2, кв. 16", false, 2);
//    parking.printInfo();

    Commercial commercial(id++, "+375293332255", "emsobak@mail.ru", 12300, 320, "г. Минск, ул. Ленина, д. 34/2, кв. 16", false, 1);
//    commercial.printInfo();
    /// -----------------------------

    Storage storage;
    storage.addHouse(house);
    storage.listHouses[0].printInfo();

//    vector<House> listHouses;
//    listHouses.push_back(house);
//    listHouses[0].printInfo();

//    Storage::listHouses.push_back(house);
//
//    Storage::listHouses[0].printInfo();

//    try {
//        Storage::upload(commercial);
//    } catch (Exception exception) {
//        exception.what();
//    }

//    Commercial commercial1;
//    try {
//        Storage::load(commercial1, 4);
//    } catch (...) {
//        cout << "ПНАЯВУ - ХУЙНЯ!!!";
//    }
//    commercial1.printInfo();
    return 0;
}

/**
  						 Дом, Коттедж
						 /
			  -> Участок
			 |	 		 \
			 | 			 Пустой
Недвижимость-|
			 |->	Квартира
			 |->	Гаражи и стоянки
			 |
			 |			 	  / Офис
			  -> Коммерческая -	Склад
						  	  \	Помещение
*/