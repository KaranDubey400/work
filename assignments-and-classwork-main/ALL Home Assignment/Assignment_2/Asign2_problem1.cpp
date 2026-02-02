#include <iostream>
#include <cstring>
using namespace std;


class student {
protected:
    int entryno;         
    char name[20] ;

public:
    void getstud() {
        cout << " enter entry number 1 for science, 2 forarts"<<endl;
           cin >> entryno; 

        if (entryno != 1 && entryno != 2) {
            cout << "invalid number" << endl;
           exit(0);
  }
        cout << "enter name";
        cin >> name;
    }

    void putstudent() const 
    {
        cout<<"enter_num"<<" "<<entryno<<" "<<"name"<<" "<<name<<endl;
    }
};

class science : public student {
    int phy, chem, math;

public:
    void get_data()  
     {
        getstud();
        cout << "enter physics marks-";
        cin >> phy;
        cout << "enter chemistry marks-";
        cin >> chem;
        cout << "enter maths marks-";
        cin >> math;
    }

    void putData() const
        {
        putstudent();
        cout << "physics  " << phy <<" chemistry " << chem << " maths " << math << endl;
    }
};


class arts : public student {
    int eng, history, eco;

public:
    void get_data() {
        getstud();
        cout << "english marks- ";
        cin >> eng;
        cout << "history marks-";
        cin >> history;
        cout << "economics marks ";
        cin >> eco;
    }

    void putdata() const {
        putstudent();
        cout << "english  " << eng << " history  " << history << " economics " << eco << endl;
    }
};

int main() {
    science s[3];
    arts a[2];

    cout << "science studnt details"<<endl;
    for (int i = 0; i < 3; i++) {
        cout << endl<<"science student" << i + 1 << endl;
        s[i].get_data();
    }

    cout << "art student info"<<endl;
    for (int i = 0; i < 2; i++) {
        cout << "art student" << i + 1 << endl;
        a[i].get_data();
    }

    cout << "science student";
    for (int i = 0; i < 3; i++) {
        cout << endl<<"student " << i + 1 << endl;
        s[i].putData();
    }

    cout << "art students"<<endl;
    for (int i = 0; i < 2; i++) {
        cout << endl<<"student" << i + 1 << endl;
        a[i].putdata();
    }

    return 0;
}
