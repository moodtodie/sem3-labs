//
// Created by Egor on 10/12/2022.
//

#include "../headers/Bicycle.h"

//  Constructors/Destructors
Bicycle::Bicycle(string brand) {
    this->brand = brand;
}

Bicycle::~Bicycle(){ brand.clear(); };

//  Getters/Setters
void Bicycle::setBrand(string brand) {
    this->brand = brand;
}

string Bicycle::getBrand() const { return brand; }

//  Overload Method
ostream &operator<<(ostream &out, Bicycle &object) {
    cout << "Factory characteristics:" << endl
         << endl << "\tFactory name: " << object.getFactoryName()
         << endl << "\tEmployees: " << object.getEmpoyees()
         << endl << "\tBrand: " << object.getBrand()
         << endl;

    return out;
}