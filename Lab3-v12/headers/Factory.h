//
// Created by Egor on 10/12/2022.
//

#ifndef LAB3_V12_FACTORY_H
#define LAB3_V12_FACTORY_H

class Factory {
    int employees;
public:
    Factory(int e = 1);
    ~Factory();

    void setEmpoyees(int emloyees){ this->employees = emloyees; }
    int getEmpoyees() const { return employees; }

    friend std::ostream& operator <<(std::ostream &out, Factory& object);
};

#endif //LAB3_V12_FACTORY_H
