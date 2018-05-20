//
// Created by Soul.专情 on 2018/5/19.
//

#include <iostream>
#include "Warehouse.h"

Warehouse::Warehouse(std::string shop_name, int capacity, std::list<Item> items) {
    this->capacity = capacity;
    this->shop_name = shop_name;
    this->items = items;
    
    std::cout<<shop_name<<" "<<capacity<<" constructor is invoked"<<std::endl;
}

Warehouse::~Warehouse() {
    std::cout<<shop_name<<" "<<capacity<<" deconstructor is invoked"<<std::endl;
}

void Warehouse::add_item(std::string name,std::string product_date, int life, double price) {
    std::list<Item>::iterator it;
    for ( it= items.begin();it != items.end();it++){
    	if (it->getName() == name) 
    	{
    		it->incr(product_date,life);
    		return;
    	}
    	
    }
    if (it == items.end())
    {
    	Item item(name,price);
    	item.incr(product_date,life);
    	items.push_back(item);
    }
}

double Warehouse::delete_item(std::string name) {
    for (std::list<Item>::iterator it = items.begin();it != items.end();it++)
    {
    	if (it->getName() == name)
    	{
    		if (it->size() > 0) 
    		{
    			it->decr();
    			return it->getPrice();
    		}

    		return 0;
    	}
    	
    }
    return -1;
}

int Warehouse::get_capacity() {
    return capacity;
}

std::string Warehouse::get_name() {
    return shop_name;
}

std::list<Item> Warehouse::get_items() {
    return items;
}
Warehouse* Warehouse::up() {
	if (capacity < 100 && get_items_count() == capacity)
	{
		Warehouse* warehouse = new Warehouse(shop_name, capacity*2, items);
		delete this;
		return warehouse;
	}
	return this;
}

Warehouse* Warehouse::down() {
	if (capacity > 0 &&  get_items_count() * 2 == capacity)
	{

		Warehouse* warehouse = new Warehouse(shop_name, capacity/2, items);
		delete this;
		return warehouse;
	}
	delete this;
	return nullptr;
}

int Warehouse::get_items_count(){
	int count = 0;
	for (std::list<Item>::iterator it = items.begin();it != items.end();it++)
	{
		count += it->size();
	}
	return count;
}