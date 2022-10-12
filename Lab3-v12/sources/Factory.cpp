//
// Created by Egor on 10/12/2022.
//

#include <iostream>
#include "../headers/Factory.h"

Factory::Factory(int e) {
    employees = e;
}

Factory::~Factory() = default;

std::ostream& operator <<(std::ostream &out, Factory& object){
    std::cout << "Factory characteristics:" << std::endl;
    std::cout << "\tEmployees: " << object.getEmpoyees() << std::endl;

    return out;
}