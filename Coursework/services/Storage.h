//
// Created by Egor on 12/4/2022.
//

#ifndef COURSEWORK_STORAGE_H
#define COURSEWORK_STORAGE_H


#include <string>
#include <map>
#include <list>
#include <fstream>
#include "../services/Exception.h"
#include "../services/Input.h"
#include "../immovables/piece/House.h"
#include "../immovables/piece/Empty.h"
#include "../immovables/flat/Flat.h"
#include "../immovables/parking/Parking.h"
#include "../immovables/commercial/Commercial.h"


class Storage {
    std::string filepath = "app.txt";
    // map <id|group> group = [house, empty, flat, parking, commercial]
    map<unsigned int, string> defineGroup;

    static bool stob(string str) {
        int i = stoi(str);
        if (i)
            return true;
        return false;
    }

protected:

public:
    vector<House> listHouses;
    vector<Empty> listEmpty;
    vector<Flat> listFlat;
    vector<Parking> listParking;
    vector<Commercial> listCommercial;
//    template<class T>
//    T load(string groupName) {
//        const string path = groupName + ".txt";
//        ifstream in;
//        in.open(path);
//        if (!in.is_open())
//            throw Exception("Невозможно открыть файл для чтения.", 0);
//
//        T className;
//
//        while (in.read((char *) &className, sizeof(className))) {
//            listCommercial.push_back(className);
//        }
//
//        in.close();
//        return;
//    }

//    template<class T>
//    void upload(T className) {
//        const string path = "data/" + to_string(className.getid()) + ".txt";
//        ofstream out;
//        out.open(path, ios::app);
//        if (!out.is_open())
//            throw Exception("Невозможно открыть файл для записи.", 0);
//
//        out.write((char *) &className, sizeof(className));
//
//        out.close();
//        return;
//    }

//    static void upload(Commercial className) {
//        const string path = to_string(className.getId()) + ".txt";
//        ofstream out;
//        out.open(path);
//        if (!out.is_open())
//            throw Exception("Невозможно открыть файл для записи.", 0);
//
//        out.write((char *) &className, sizeof(className));
//
//        out.close();
//        return;
//    }
//
//    static void load(Commercial className, unsigned int id) {
//        const string path = to_string(id) + ".txt";
//        ifstream in;
//        in.open(path);
//        if (!in.is_open())
//            throw Exception("Невозможно открыть файл для чтения.", 0);
//
////        Commercial className();
//        in.read((char *) &className, sizeof(className));
//
//        in.close();
//    }

    template<typename T>
    static void upload(T className) {
        const string path = to_string(className.getId()) + ".txt";
        ofstream out;
        out.open(path);
        if (!out.is_open())
            throw Exception("Невозможно открыть файл для записи.", 0);

        out << className;

        out.close();
    }

    template<typename T>
    void load(T className, unsigned int id) {
        const string path = to_string(id) + ".txt";
        ifstream in;
        in.open(path);
        if (!in.is_open())
            throw Exception("Невозможно открыть файл для чтения.", 0);
        //  id и class type знаем из главного файла
        string classType;
        //  all
        string phone;
        string email;
        float cost = -1;
        double sqr = -1;
        string addr;
        bool actual = false;
        //  piece
        bool pond = false;
        bool plant = false;
        bool commun = false;
        //  empty
        bool suifcons = false;
        bool suiffarm = false;
        //  house
        int parking = -1;
        //  flat & house
        int rooms = -1;
        int floor = -1;
        //  flat
        bool balcony = false;
        //  commercial & parking
        int type = -1;

        string str;
        while (getline(in, str)) {
            string name = str.substr(0, str.find(' '));
            string value = str.substr(str.find(' ') + 1, str.find('\n'));
            if (name == "class")
                classType = value;
            else if (name == "phone")
                phone = value;
            else if (name == "email")
                email = value;
            else if (name == "cost")
                cost = stof(value);
            else if (name == "sqr")
                sqr = stod(value);
            else if (name == "addr")
                addr = value;
            else if (name == "actual")
                actual = stob(value);
            else if (name == "pond")
                pond = stob(value);
            else if (name == "plant")
                plant = stob(value);
            else if (name == "commun")
                commun = stob(value);
            else if (name == "suifcons")
                suifcons = stob(value);
            else if (name == "suiffarm")
                suiffarm = stob(value);
            else if (name == "parking")
                parking = stoi(value);
            else if (name == "rooms")
                rooms = stoi(value);
            else if (name == "floor")
                floor = stoi(value);
            else if (name == "balcony")
                balcony = stob(value);
            else if (name == "type")
                type = stoi(value);
        }

        if (classType == "house") {
            House house(id, phone, email, cost, sqr, addr, actual, pond, plant, commun,
                        floor, rooms, parking);
            listHouses.push_back(house);
        } else if (classType == "empty") {
            Empty empty(id, phone, email, cost, sqr, addr, actual, pond, plant, commun,
                        suifcons, suiffarm);
            listEmpty.push_back(empty);
        } else if (classType == "flat") {
            Flat flat(id, phone, email, cost, sqr, addr, actual, rooms, floor, balcony);
            listFlat.push_back(flat);
        } else if (classType == "parking") {
            Parking parking(id, phone, email, cost, sqr, addr, actual, type);
            listParking.push_back(parking);
        } else if (classType == "commercial") {
            Commercial commercial(id, phone, email, cost, sqr, addr, actual, type);
            listCommercial.push_back(commercial);
        }
        in.close();
    }

    void addHouse(House &house) {
        listHouses.push_back(house);
        try {
            load(house, house.getId());
        } catch (Exception exception) {
            exception.what();
        } catch (...) {
            unexpected();
        }
    }

    void addEmpty(Empty &empty) {
        listEmpty.push_back(empty);
        load(empty, empty.getId());
    }

    void addFlat(Flat &flat) {
        listFlat.push_back(flat);
        load(flat, flat.getId());
    }

    void addParking(Parking &parking) {
        listParking.push_back(parking);
        load(parking, parking.getId());
    }

    void addCommercial(Commercial &commercial) {
        listCommercial.push_back(commercial);
        load(commercial, commercial.getId());
    }

//    void addImmovable(House *house = nullptr, Empty *empty = nullptr, Flat *flat = nullptr,
//                      Parking *parking = nullptr, Commercial *commercial = nullptr) {
//        try {
//            if (house != nullptr) {             //  Home
//                defineGroup.emplace(house->getId(), "house");
//                upload(house, "house");
//            } else if (empty != nullptr) {      //  Empty
//                defineGroup.emplace(empty->getId(), "empty");
//                upload(empty, "empty");
//            } else if (flat != nullptr) {       //  Flat
//                defineGroup.emplace(flat->getId(), "flat");
//                upload(flat, "flat");
//            } else if (parking != nullptr) {    //  Parking
//                defineGroup.emplace(parking->getId(), "parking");
//                upload(parking, "parking");
//            } else if (commercial != nullptr) { //  Commercial
//                defineGroup.emplace(commercial->getId(), "commercial");
//                upload(commercial, "commercial");
//            }
//        } catch (Exception exception) {
//            exception.what();
//        } catch (...) {
//            unexpected();
//        }
//    }
};


#endif //COURSEWORK_STORAGE_H
