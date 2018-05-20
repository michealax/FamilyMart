//
// Created by Soul.专情 on 2018/5/16.
//

#ifndef LAB3_ITEM_H
#define LAB3_ITEM_H

#include <string>
#include <list>

class Item {
    std::string name;
    double price;
    std::list<std::string> product_dates;
    std::list<int> lifes;
public:
    Item();
    Item(std::string name, double price);
    ~Item();
    std::string getName();
    double getPrice();
    void incr(std::string product_date, int life);
	  void decr();
	  int size();
};


#endif //LAB3_ITEM_H
