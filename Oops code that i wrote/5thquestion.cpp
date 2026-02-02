#include <iostream>
#include <string>
using namespace std;

class Directory
{
private:
      string name;
    string address;
     string telephone;
    string mobile;
     string hofamily;

   public:
    void inputDetails()
    {
        cout << "name"<<endl;
        getline(cin, name);

        cout << "address: "<<endl;
        getline(cin, address);

        cout << "telephone number:"<<endl;
        getline(cin, telephone);

        cout << "mobile num "<<endl;
        getline(cin, mobile);

        cout << "head of family"<<endl;
        getline(cin, hofamily);
    }

    
    void displaydetails()
    {
        cout << "directory info"<<endl;
        cout << "name    " << name << endl;
        cout << "address  " << address << endl;
        cout << "telephone  " << telephone << endl;
        cout << "mobile number " << mobile << endl;
        cout << "head of family " << hofamily << endl;
    }
};

int main()
{
    Directory person;

    cout << "enter directory details";
    person.inputDetails();

    person.displaydetails();

    return 0;
}
