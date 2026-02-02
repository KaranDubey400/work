#include <iostream>
using namespace std;


class degree {
      
    public:
    void get_degree() 
    {
        cout << "i got degree" << endl;
    }
};


class undergraduate : public degree {
      public:
   
      void get_degree()
       {
        cout << "i am an undergraduate" << endl;
    }
};

class postgraduate : public degree {
     
    public:

    void get_degree() {
        cout << "i am a postgraduate" << endl;
    }
};

int main() {
    degree d;
    undergraduate ug;
    postgraduate pg;

    d.get_degree();    
    ug.get_degree();   
    pg.get_degree();  

    return 0;
}
