//
// Created by Soul.专情 on 2018/5/19.
//

#include <iostream>
#include "Shop.h"

Shop::Shop(std::string shop_name) {
    this->shop_name = shop_name;
    this->sales = 0;
    this->warehouse = nullptr;
}

Shop::~Shop() {}

std::string Shop::get_name() {
    return shop_name;
}

double Shop::get_sales(){
	return sales;
}

Warehouse* Shop::get_warehouse() {
    return warehouse;
}
void Shop::purchase(std::string name, std::string product_date, int life, double price) {
    if (warehouse == nullptr){
      warehouse = new Warehouse(shop_name, 25,std::list<Item>());
    }
    if (warehouse->get_items_count() == warehouse->get_capacity())
        warehouse = warehouse->up();
    warehouse->add_item(name, product_date,life, price);
}

void Shop::sell(std::string name, double discount) {
    double sale = warehouse->delete_item(name);
    if (sale == -1 || sale == 0) 
    {
    	std::cout<<name<<" is sold out"<<std::endl;
    		return;
    }
    if (warehouse->get_items_count() * 2 == warehouse->get_capacity())
        warehouse = warehouse->down();
    sales += sale * discount;
}

