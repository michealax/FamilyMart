//
// Created by Soul.专情 on 2018/5/20.
//


#include <iostream>
#include <fstream>
#include "Control.h"

Control::Control() {
    event("init_shop","shop.txt");
}

Control::~Control() {
    std::list<Shop>::iterator it;
    for (it = shops.begin(); it!= shops.end();it++){
       delete it->get_warehouse();
    }
}

void Control::listener() {
    std::cout<<">"<<std::endl;
    std::string command;
    std::getline(std::cin, command);
    while (command != "close"){
        unsigned int index = command.find(" ");
        if (index != std::string::npos){
            event(command.substr(0,index), command.substr(index+1,command.length()));
        } else
            event(command);
        std::cout<<">"<<std::endl;
        std::getline(std::cin,command);
    }


}

void Control::event(std::string command, std::string file) {
    if (command == "init_shop"){
        std::ifstream fin(file);
        std::string line;

        Shop shop("SHOP1");

        std::string name;
        std::string price;
        std::string life;
        std::string date;
        fin>>name>>price;
        fin >>name>>price>>life>>date;
        while (getline(fin, line)) {
            fin >>name>>price>>life>>date;
            shop.purchase(name,date,atoi(life.c_str()),atof(price.c_str()));
        }
        fin.close();
        shops.push_back(shop);

    }

    if (command == "purchase"){
        std::ifstream fin(file);
        std::string line;

        std::string name;
        std::string price;
        std::string life;
        std::string date;
        fin>>price>>life>>name;

        std::list<Shop>::iterator it;
        for (it = shops.begin(); it!= shops.end();it++){
            if (it->get_name() == name)
                break;
        }

        if (it == shops.end()){
            std::cout<<"The shop can not be found"<<std::endl;
            return;
        }

        if (it->get_warehouse()->get_items_count() + atoi(life.c_str()) > 100){
            std::cout<<"The warehouse too small"<<std::endl;
            return;
        }

        fin >>name>>price>>life>>date;
        while (getline(fin, line)) {
            fin >>name>>price>>life>>date;
            //std::cout<<name<<price<<life<<date<<std::endl;
            it->purchase(name,date,atoi(life.c_str()),atof(price.c_str()));
        }
        fin.close();
    }

    if (command == "sell"){
        std::ifstream fin(file);
        std::string line;

        std::string shop_name;
        std::string item_name;
        double discount = 1.0;

        unsigned int index , index1;

        while (std::getline(fin,line)){
            index = line.find(" ");
            index1 = line.find(" ",index+1);
            if (index1 != -1){
                discount = atof(line.substr(index+1,index1-index-1).c_str());
                shop_name = line.substr(index1+1,line.length());
            } else{
                shop_name = line.substr(index+1,line.length());
            }

            std::list<Shop>::iterator it;
            for (it = shops.begin(); it!= shops.end();it++){
                if (it->get_name() == shop_name)
                    break;
            }

            //std::cout<<(it == shops.end())<<std::endl;
            while (std::getline(fin,line) && line != ""){
                item_name  = line;
                it->sell(item_name,discount);
            }
        }
        fin.close();

        double sum = getAllSales()- (shops.size()-1)*55;
        for (int i = 1; i*55 <= sum; ++i) {
            shop_name = "SHOP"+std::to_string(shops.size()+i);
            shops.push_back(Shop(shop_name));
        }
    }

    if (command == "show_sale_amount"){
        std::cout<<"sale_amount "<<getAllSales()<<std::endl;
    }

    if (command == "show_all_shop_name"){
        std::list<Shop>::iterator it;
        for (it = shops.begin(); it!= shops.end();it++){
            std::cout<<it->get_name()<<std::endl;
        }
    }
}

double Control::getAllSales() {
    double sum = 0;
    std::list<Shop>::iterator it;
    for (it = shops.begin(); it!= shops.end();it++){
        sum += it->get_sales();
    }
   // std::cout<<"sum"<<sum<<std::endl;
    return sum;
}