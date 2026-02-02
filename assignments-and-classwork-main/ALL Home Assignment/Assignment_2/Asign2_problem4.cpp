#include <iostream>
#include <cstring>
using namespace std;


class patient {
protected:
    char name[50];
    char disease[50];

public:
    
    patient(char* n, char* d) {
        strcpy(name, n);
        strcpy(disease, d);
    }

       void putdata() {
        cout << " patient name " << name << endl;
        cout << "disease name " << disease << endl;
    }
};

class In_patient : public patient {
    float roomrent;

public:
    
        In_patient(char* n, char* d, float rent): patient(n, d) {
        roomrent = rent;
    }

    void putdata() 
    { 
        patient::putdata();
        cout << "rent is " << roomrent << endl;
    }
};


class out_patient : public patient {
    private:
    float OPD_charge;

    public:
   
    out_patient(char* n, char* d, float charge) : patient(n, d) {
        OPD_charge = charge;
        
    }

    void putdata() {
        patient::putdata();
        cout << "opd Charges " << OPD_charge << endl;
    }
};

int main() {
    In_patient s1("karn", "fever", 2400.5);
    out_patient s2("sush", "cold", 500.9);

    cout << "patent_info";
    s1.putdata();

    cout << "patients info";
    s2.putdata();

    return 0;
}
