//
// Created by Soul.专情 on 2018/5/19.
//

#ifndef LAB3_WAREHOUSE_H
#define LAB3_WAREHOUSE_H


#include <list>
#include <string>
#include <map>
#include "Item.h"

class Warehouse {
    int capacity;
    std::string shop_name;
    std::list<Item> items;
public:
    Warehouse(std::string shop_name, int capacity, std::list<Item> items);
    ~Warehouse();
    void add_item(std::string name,std::string product_date, int life, double price);
    double delete_item(std::string name);
    int get_capacity();
    std::string get_name();
    std::list<Item> get_items();
    Warehouse* up();
    Warehouse* down();
    int get_items_count();
};


#endif //LAB3_WAREHOUSE_H
