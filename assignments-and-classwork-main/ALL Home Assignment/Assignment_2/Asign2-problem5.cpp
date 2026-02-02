#include <iostream>
#include <cstring>
using namespace std;

class Publication {
      
    protected:

    char title[40];
 
       public:

    Publication(char* t) {
        strcpy(title,t);
    
    }

    void print() {
        cout << "title  " << title << endl;

    }

};


class Book : virtual public Publication {
      protected:
    float accession_no;

    public:

    Book(char *t, float a) : Publication(t) 
    {
        accession_no = a;
    }

    void print() {
        Publication::print();
        cout << "access number -" << accession_no << endl;
    }
};


class Magazine : virtual public Publication {
  
    protected:

    int volume_no;

    public:

    Magazine(char* t, int v) : Publication(t) {
        volume_no = v;
    }

    void print() {

        Publication::print();
        cout << "vol. number-" << volume_no << endl;

    }

};

class Journal : public Book, public Magazine {
        
    public:
    
          Journal(char* t, float a, int v) : Publication(t), Book(t, a), Magazine(t, v) 
          {
            
          }

    void print()
     {
        Publication::print();
        cout << "acces_num -" << accession_no <<" "<<"vol_num=-"<<" "<<volume_no<<endl;;
    
    }
};

int main() {
    Journal s1("IEEOOP", 681.3, 1);

    cout << "Journal" << endl;
    s1.print();

    return 0;
}