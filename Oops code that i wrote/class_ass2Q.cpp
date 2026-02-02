#include <iostream>
using namespace std;


class fruit1 {
   protected:

    int total;


    public:
    fruit1() {
        total = 0;
    }

    void show1() {
        cout << "total fruits in basket"  << total << endl;
    }
};


class apples1 : public fruit1 { 

     private:

    int apples;

    public:
    apples1(int a) {
        apples = a;
        total += apples;
    }

    int get_apple() {
        return apples;
    }
};


class mangoes1 : public fruit1 {
   private:
    int mangoes;

   public:
    mangoes1(int m) {
        mangoes = m;
        total += mangoes;
    }

    int get_mangoes() {
        return mangoes;
    }
};

int main() {

    int apple, mango;

    cout << "enter no. of apples";

    cin >> apple;

    cout << "enter number of mango";

    cin >> mango;

    apples1 apple_s1(apple);

    mangoes1 mango_s2(mango);

    cout << "no. of apple" << apple_s1.get_apple() << endl;
    
    cout << "no. of mango " << mango_s2.get_mangoes() << endl;

    cout << "total"<< (apple_s1.get_apple() + mango_s2.get_mangoes()) << endl;

    return 0;
}
