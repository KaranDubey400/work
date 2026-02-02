#include <iostream>
#include <cstring>
using namespace std;

class Cell_user {
protected:
    char * name;
    int used_time;   

public:
    Cell_user(char* k, int u) {
        name = k;
        used_time = u;
    }

    virtual void printBill() {
       
    }
   
    
    virtual int get_talktimeleft() = 0;

   
};


class Prepaid : public Cell_user {
    int total_time;

      public:

    Prepaid(char* k, int total, int used) : Cell_user(k, used) {
        total_time = total;
    }

    int get_talktimeleft() override 
    {
        return total_time - used_time;
    }


};

class Postpaid : public Cell_user {
       private:

    int free_time;
    float rate_per_pulse;

    public:

    Postpaid(char* k, int freetalk, int used): Cell_user(k, used) {
        free_time = freetalk;
        rate_per_pulse = 1.90;
    }

    int get_talktimeleft() override {
        if (used_time <= free_time)
            return free_time - used_time;
        else
            return 0;
    }

    void printBill() override {
        cout << "postpaid bill"<<endl;
        cout << "name -" << name << " " << "free ttime" << free_time << " mins" << endl;
        cout << "used ttime" << used_time << " mins" << endl;

        
        if (used_time > free_time)
         {

            int extra = used_time - free_time;

            float bill = extra * rate_per_pulse;


            
            cout << "extra pulse " << extra <<" "<<"rate per puls" << rate_per_pulse << endl;

            cout << "total bill==" << bill << endl;

        } else {
            cout << "total bill is 0" << endl;
        }

    }

};


int main() {
    Prepaid p1("karan", 300, 120);
    Postpaid p2("sush", 200, 260);

    cout << "\n--- prepaid user ---\n";
    cout << "talk time left = " << p1.get_talktimeleft() << " mins "<<endl;

    cout << "\n---postpaid user ---\n";
    cout << "talk time left = " << p2.get_talktimeleft() << " min"<<endl;
    p2.printBill();

   
}
