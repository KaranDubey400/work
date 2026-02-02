#include <iostream>
using namespace std;

class cashregister 
{
    private:
    int cashonhand;

     public:

    cashregister()
     {

        cashonhand = 500;
    }

  cashregister(int amount){     
        cashonhand = amount;
    }


       int getcurrntbal() {
        return cashonhand;
    }
 void acceptamount(int amnt)
       {
        cashonhand += amnt;
    }

};

class dispensertype {
    private:
    int numofitems;
    int cost;

     public:

    dispensertype()          
        {
        numofitems = 50;
        cost = 50;
    }


         dispensertype(int items, int price)
          {
        numofitems = items;
        cost = price;
    }



    int getnumitems() {
        return numofitems;
    }
     void makesale() {
        numofitems--;
    }

    int get_cost() {
        return cost;
    }

   

};

void showselect() {

    cout << endl<<"candy machine menu"<<endl;

    cout << "1 Candy"<<endl;

    cout << "2 Chips"<<endl;

    cout << "3 Gum"<<endl;

    cout << "4 Cookies"<<endl;

    cout << "enter ur choice"<<endl;   }


void sellproduct(dispensertype &item, cashregister & regg) {

    if (item.getnumitems() <= 0) {
        cout << "sold out."<<endl;
        return;
    }

     int money;
    cout << "cost" << item.get_cost() << endl;
      cout << "insert money ";
    cin >> money;

    if (money < item.get_cost()) {
        cout << "not enough money. item not sold."<<endl;
    }
     
    else {

        item.makesale();

        regg.acceptamount(item.get_cost());

        cout << "Please collect your item."<<endl;

        if (money > item.get_cost()){
            cout << "change returned " << money - item.get_cost() << endl;
        }

    }
}

int main() {
    cashregister r1;

    dispensertype candy(20, 10);
    dispensertype chips(15, 20);
    dispensertype gum(30, 5);
    dispensertype cookies(10, 25);

    int choice;
    showselect();
    cin >> choice;

    switch (choice) {
        case 1:
         sellproduct(candy, r1);
          break;
        case 2:
         sellproduct(chips, r1); 
         break;
        case 3: 
        sellproduct(gum, r1);
         break;
        case 4:
         sellproduct(cookies, r1);
          break;
        default:
         cout << "invalid choice"<<endl;
    }

    return 0;
}
