#include <iostream>
#include <fstream>
#include "Warehouse.h"
#include "Control.h"

using namespace std;
void read_shop_txt(Shop &shop);
void read_shop_txt(Warehouse*);
int main() {
//    list<Shop> shops;
//    Shop shop("SHOP1");
//    shops.push_back(shop);
    //Warehouse* warehouse = new Warehouse("shop1",25,list<Item>());
  //  read_shop_txt(shop);

    //for (int i = 0; i < 6; i++) {
//        shop.sell("milk");
//    shop.sell("milk");
//    shop.sell("milk");
//    shop.sell("milk");
//    shop.sell("milk");
//    shop.sell("milk");
//    shop.sell("milk");
    //shop.sell("milk");
   // }

  //  warehouse = warehouse->up();
//    warehouse->delItem(Item("milk",2.5,Date(2018,4,2),7));
//    list<Item> list1 = warehouse->get_items();
//    list<Item>::iterator it;
//    it = list1.begin();
//    while (it != list1.end()){
//        cout<<it->size()<<" ";
//        cout<<it->getName()<<endl;
//        it++;
//    }
//Warehouse *warehouse = new Warehouse("sop1",25,0);
//Item item("milk",2.5,Date(2018,4,2),7);
//    Item item1("milk",2.5,Date(2018,4,2),7);
//    Item item2("milk",2.5,Date(2018,4,2),7);
//    warehouse->addItem(item);
//    warehouse->addItem(item1);
//    warehouse->addItem(item2);
//    Warehouse* warehouse = shop.get_warehouse();
//    cout<<warehouse->get_name()<<endl;
//    list<Item> map1 = warehouse->get_items();
//    list<Item>::iterator it;
//    it = map1.begin();
//    while (it != map1.end()){
//        cout<<it->size();
//        cout<<it->getName()<<endl;
//        it++;
//    }
//    for (list<Shop>::iterator it = shops.begin();it != shops.end();it++) {
//        delete shop.get_warehouse();
//    }
    Control control;
    control.listener();
    return 0;
}

void read_shop_txt(Shop &shop){
    ifstream fin("shop.txt");
    string line ;
    string name;
    string price;
    string life;
    string date;
    fin>>name>>price;
    fin >>name>>price>>life>>date;
    while (getline(fin, line)) {
        fin >>name>>price>>life>>date;
        shop.purchase(name,date,atoi(life.c_str()),atof(price.c_str()));
    }
}

void read_shop_txt(Warehouse* warehouse){
    ifstream fin("shop.txt");
    string line ;
    string name;
    string price;
    string life;
    string date;
    fin>>name>>price;
    fin >>name>>price>>life>>date;
    while (getline(fin, line)) {
        fin >>name>>price>>life>>date;
        warehouse->add_item(name,date,atoi(life.c_str()),atof(price.c_str()));
    }
}

