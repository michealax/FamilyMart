//
// Created by Soul.专情 on 2018/5/19.
//

#ifndef LAB3_SHOP_H
#define LAB3_SHOP_H


#include <string>
#include "Warehouse.h"

class Shop {
    std::string shop_name;
    double sales;

    bool inited;
public:
    Warehouse* warehouse;
    Shop(std::string shop_name);
    ~Shop();
    std::string get_name();
    double get_sales();
    void purchase(std::string name, std::string product_date, int life, double price);
    void sell(std::string name, double discount = 1.0);
    Warehouse* get_warehouse();
};


#endif //LAB3_SHOP_H
