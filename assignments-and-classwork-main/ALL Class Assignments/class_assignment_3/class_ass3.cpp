#include <iostream>
#include <string>
using namespace std;


class marks {
     
    protected:
    int rno;
    string name;
    static int count;

    public:
    marks(string n) {
        rno = ++count;
        name = n;
    }

    int getroll() {
        return rno;
    }

    string getname() {
        return name;
    }
};


int marks::count = 0;


class physics : virtual public marks {
    protected:


    int phy;

    public:

    physics(string n, int p) : marks(n) {

        phy = p;
    }
};


class chemistry : virtual public marks {
      protected:
    int chem;

    public:
    chemistry(string n, int c) : marks(n) {
        chem = c;
    }
};


class mathematics : virtual public marks {
   protected:

    int math;
 
   public:

    mathematics(string n, int m) : marks(n) {
        math = m;
    }
};

class student : public physics, public chemistry, public mathematics { 

    private:
    int total;

    public:
    student(string n1, int p1, int c1, int m1)
        : marks(n1), physics(n1, p1), chemistry(n1, c1), mathematics(n1, m1) {
        total = phy + chem + math;
    }

    int getoverall() {
        return total;
    }

    void display() {
        cout << rno << endl<< name << " "  << phy << "  "  << chem << " "  << math << " "  << total << endl;
    }
};

int main() {
    int n;
    cout << " number of students ";
    cin >> n;

    student* s[n];
    int p, c, m;
    string name;
    int classTotal = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> name;

        cout << "enter physics marks ";
        cin >> p;

        cout << "chemistry marks ";
        cin >> c;

        cout << " mathematics marks ";
        cin >> m;

        s[i] = new student(name, p, c, m);
        classTotal += s[i]->getoverall();
    }

    cout << "\nroll\tname\tphy\tchem\tmath\ttotal\n";
    for (int i = 0; i < n; i++) {
        s[i]->display();
    }


    cout << "\naverage marks of the class = "
         << (float)classTotal / n << endl;

    return 0;
}
