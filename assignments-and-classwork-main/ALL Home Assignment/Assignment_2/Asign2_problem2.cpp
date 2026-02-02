#include <iostream>
using namespace std;

class Electricity {
protected:
    int units;
    float cost;

public:
    Electricity() {
        units = 0;
        cost = 0;
    }

    Electricity(int u) {
        units = u;
        cost = 0;
    }

    virtual void bill() {
        if (units <= 100) {
            cost = units * 0.50;
        }
        else if (units <= 300) {
            cost = (100 * 0.50) + (units - 100) * 0.60;
        }
        else {
            cost = (100 * 0.50) + (200 * 0.60) + (units - 300) * 0.80;
        }

        cout << "Bill without surcharge rs-" << cost << endl;
    }
};

class More_electricity : public Electricity {
public:
    More_electricity(int u) : Electricity(u) {}

    void bill() override {
        Electricity::bill();

        if (cost > 250) {
            float surcharge = (cost - 250) * 0.15;
            cost += surcharge;
        }

        cout << "final bill with surcharge  rs" << cost << endl;
    }
};

int main() {
    int ut;
    cout << "units ";
    cin >> ut;

    More_electricity s1(ut);
    s1.bill();

    return 0;
}
