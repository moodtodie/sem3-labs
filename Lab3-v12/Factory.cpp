//
// Created by Egor on 10/12/2022.
//

#include "Factory.h"

using namespace std;

//  Constructors/Destructors
Factory::Factory(std::string factoryName, int e) {
    this->factoryName = factoryName;
    employees = e;
}

Factory::~Factory(){ factoryName.clear(); };

//  Getters/Setters
void Factory::setEmpoyees(int emloyees) {
    this->employees = emloyees;
}

int Factory::getEmpoyees() const { return employees; }

void Factory::setFactoryName(string name) {
    this->factoryName = name;
}

string Factory::getFactoryName() const { return factoryName; }

//  Overload Method
ostream &operator<<(ostream &out, Factory &object) {
    cout << "Factory characteristics:" << endl
    << endl << "\tFactory name: " << object.getFactoryName()
    << endl << "\tEmployees: " << object.getEmpoyees()
//    << endl << "\tBrand: " << object.getBrand()
    << endl;

    return out;
}