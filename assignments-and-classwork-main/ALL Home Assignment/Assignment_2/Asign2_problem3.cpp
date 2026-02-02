#include <iostream>
using namespace std;

class time {
    int hrs, min, sec;

public:
  
    time()    {
        hrs = 0;
        min = 0;
        sec = 0;

    }

   
    time(int h, int m, int s) 
    {
        hrs = h;
        min = m;
        sec = s;

    }

    void display_24() const {

        cout << hrs << ":" << min << ":" << sec << endl;
    }

   
    void display_12() const   {
        int h = hrs % 12;
         if (h == 0)
         {
            h = 12;
         }

        cout << h << ":" << min << ":" << sec << endl;
    }

  
    time operator+(const time& t)  {
        time temp;

        temp.sec = sec + t.sec;

        temp.min = min + t.min + temp.sec / 60;
        temp.sec = temp.sec % 60;

        temp.hrs = hrs + t.hrs + temp.min / 60;
        temp.min = temp.min % 60;
        temp.hrs = temp.hrs % 24;

        return temp;

        
    }
};

int main()
 {

    time t1(10, 43, 30);
    time t2(5, 30, 15);
    time t3;   
  t3 = t1 + t2;

    cout << "time 1 ,24 hour";
    t1.display_24();
    cout << "time 1 ,12 hour";
    t1.display_12();

    cout << endl;

    cout << "time 2 ,24 hour ";
    t2.display_24();
    cout << "time 2 ,12 hour ";
    t2.display_12();

    cout << endl;

    cout <<" answer time ,24 hour: ";
    t3.display_24();
    cout << "answertime ,12 hour ";
    t3.display_12();

    return 0;
}
