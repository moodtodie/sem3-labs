//
// Created by Egor on 10/12/2022.
//

#ifndef LAB3_V12_FACTORY_H
#define LAB3_V12_FACTORY_H

#include <iostream>

class Factory {
protected:
    std::string factoryName;
    int employees;
public:
    Factory(std::string factoryName = "", int e = 1);
    ~Factory();

    void setEmpoyees(int emloyees);
    int getEmpoyees() const;

    void setFactoryName(std::string name);
    std::string getFactoryName() const;

    friend std::ostream& operator <<(std::ostream &out, Factory& object);
};

#endif //LAB3_V12_FACTORY_H