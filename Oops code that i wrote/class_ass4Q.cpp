#include <iostream>
using namespace std;

class Vehicle {
    protected:
    float mileage;
    float price;
 
    public:
    Vehicle(float m, float p)
     {
        mileage = m;
        price = p;
    }
};

class Car : public Vehicle 
{
     protected:


    float ownershipCost;
    int warranty;
    int seats;
    string fuel;

     public:
    Car(float m, float p, float oc, int w, int s, string f) : Vehicle(m, p)
         {
        ownershipCost = oc;
        warranty = w;
        seats = s;
        fuel = f;
    }
};

class Bike : public Vehicle {
    protected:
    int cylinders;
    int gears;
    string cooling;
    string wheels;
    float tank;

    public:
    Bike(float m, float p, int c, int g, string co, string wh, float t): Vehicle(m, p) 
        {
        cylinders = c;
        gears = g;
        cooling = co;
        wheels = wh;
        tank = t;
    }


};

class Audi : public Car {
    string model;

public:
    Audi(string mo, float m, float p, float oc, int w, int s, string f)  : Car(m, p, oc, w, s, f) {
        model = mo;
    }

    void show() {
        cout << "\nAudi car\n";
        cout << model << endl;
        cout << ownershipCost << endl;
        cout << warranty << endl;
        cout << seats << endl;
        cout << fuel << endl;
        cout << mileage << endl;
        cout << price << endl;
    }
};

class Ford : public Car {
    string model;

public:
    Ford(string mo, float m, float p, float oc, int w, int s, string f)    : Car(m, p, oc, w, s, f) {
        model = mo;
    }

    void show() 
    {
        cout << "\nFord car\n";
        cout << model << endl;
        cout << ownershipCost << endl;
        cout << warranty << endl;
        cout << seats << endl;
        cout << fuel << endl;
        cout << mileage << endl;
        cout << price << endl;
    }
};

class Bajaj : public Bike {
    string make;

public:
    Bajaj(string mk, float m, float p, int c, int g, string co, string wh, float t) : Bike(m, p, c, g, co, wh, t) 
        {
        make = mk;
    }

    void show() {
        cout << "\nBajaj bike\n";
        cout << make << endl;
        cout << cylinders << endl;
        cout << gears << endl;
        cout << cooling << endl;
        cout << wheels << endl;
        cout << tank << endl;
        cout << mileage << endl;
        cout << price << endl;
    }
};

class TVS : public Bike {
    string make;

public:
    TVS(string mk, float m, float p, int c, int g, string co, string wh, float t)
        : Bike(m, p, c, g, co, wh, t) {
        make = mk;
    }

    void show() {
        cout << "\nTVS bike\n";
        cout << make << endl;
        cout << cylinders << endl;
        cout << gears << endl;
        cout << cooling << endl;
        cout << wheels << endl;
        cout << tank << endl;
        cout << mileage << endl;
        cout << price << endl;
    }
};

int main() {

    Audi a("A6", 15, 5500000, 200000, 5, 5, "petrol");
    Ford f("Mustang", 10, 7500000, 300000, 4, 4, "petrol");

    Bajaj b("Pulsar", 50, 120000, 1, 5, "air", "alloy", 11);
    TVS t("Apache", 48, 135000, 1, 5, "oil", "alloy", 12);

    a.show();
    f.show();
    b.show();
    t.show();

    return 0;
}
