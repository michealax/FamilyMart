//
// Created by Soul.专情 on 2018/5/20.
//

#ifndef LAB3_CONTROL_H
#define LAB3_CONTROL_H

#include "Shop.h"


class Control {
public:
    Control();
    ~Control();
    void listener();
private:
    std::list<Shop> shops;
    void event(std::string, std::string file = "");
    double getAllSales();
};


#endif //LAB3_CONTROL_H
