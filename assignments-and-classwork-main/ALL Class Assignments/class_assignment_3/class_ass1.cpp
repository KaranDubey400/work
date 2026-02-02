#include <iostream>
using namespace std;

class mammal {
public:
    void show1() {
        cout << "i am a mammal" << endl;
    }
};


class marine_animal {
public:
    void show2() {
        cout << "i am a marine animal" << endl;
    }
};

class bluewhale : public mammal, public marine_animal {
public:
    void show3() {
        cout << "i belong to both the categories: mammals as well as marine animals" << endl;
    }
};

int main() {

   
    mammal s1;
    s1.show1();

    
    marine_animal s2;
    s2.show2();

    
    bluewhale s3;
    s3.show3();

   
    s3.show2();
    s3.show3();

    return 0;
}
