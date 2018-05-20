//
// Created by Soul.专情 on 2018/5/16.
//

#include "Item.h"

Item::Item() {
    this->name = "";
    this->price = 0;
}

Item::Item(std::string name, double price) {
    this->name = name;
    this->price = price;
}

Item::~Item() {

}

std::string Item::getName() {
    return name;
}

double Item::getPrice() {
    return price;
}

void Item::incr(std::string product_date, int life){
	product_dates.push_back(product_date);
	lifes.push_back(life);
}

void Item::decr(){
	product_dates.pop_front();
	lifes.pop_front();
}

int Item::size(){
	return this->product_dates.size();
}