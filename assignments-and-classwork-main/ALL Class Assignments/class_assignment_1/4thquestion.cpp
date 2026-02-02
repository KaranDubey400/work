#include <iostream>
#include <cstring> 
using namespace std;

class Bankaccount 
{
    private:
    char name[50];
    char address[100];
    char account_type[20];
    int balance;
    int num_transactions;
    char account_num[10];

    static int countofaccount; 

    public:
   
    Bankaccount() 
    {
        strcpy(name, "");
        strcpy(address, "");
        strcpy(account_type, "");
        balance = 0;
        num_transactions = 0;
        strcpy(account_num, "");
    }

    
    void initialize(const char* n, const char* addr, const char* type, int bal) {
        strcpy(name, n);
        strcpy(address, addr);
        strcpy(account_type, type);
        balance = bal;
        num_transactions = 0;
    }

   
    void generateAccountNumber()
     {
        sprintf(account_num, "BA%d", 1000 + countofaccount);
        countofaccount++;
    }

   
    void display()
     {

        cout << "account number" << account_num << endl;

        cout << "name" << name << endl;

        cout << "address  " << address << endl;

        cout << "account type" <<account_type << endl;

        cout << "balance " << balance << endl;

        cout << "number of transaction " << num_transactions << endl;
      
    }

   
    void deposit(double amount)
     {
        if(amount > 0)
         {

            balance += amount;

            num_transactions++;
                cout << " " << amount << " deposited successfully"<<endl;
        } 
        else 
        {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) 
    {
        if(amount > 0 && balance >= amount)
         {
            balance -= amount;

            num_transactions++;

            cout <<  amount << " withdrawn successfully"<<endl;
        }
         else
          {
            cout << "insufficient balance "<<endl;
        }
    }

    
    void changeAddress(const char* newadd)
     {
        strcpy(address, newadd);

        num_transactions++;

        cout << "address updated " << address << endl;
    }

    
    int getNumTransactions() 
    {
        return num_transactions;
    }

    
    const char* getAccountNumber() 
    {
        return account_num;
    }
};


int Bankaccount::countofaccount = 0;

int main() {
    const int MAX = 5;
    Bankaccount accounts[MAX];

    
    for(int i = 0; i < MAX; i++) {
        char name[50], address[100], type[20];
        double balance;

        cout << endl<<"depositor " << i+1 << endl;
        cout << "enter name ";
        cin.ignore();

        cin.getline(name, 50);
        cout << "enter address "<<endl;

        cin.getline(address, 100);
        cout << " account type "<<endl;

        cin.getline(type, 20);
        cout << " initial balance "<<endl;
        cin >> balance;

        accounts[i].initialize(name, address, type, balance);

        accounts[i].generateAccountNumber();
    }

    
    for(int i = 0; i < MAX; i++) {
        cout << endl<<"operations on depositor " << i+1 << endl;

   
        cout << endl <<"initial Information"<<endl;
        accounts[i].display();

        
        double dep;
        cout << "amount to deposit";
        cin >> dep;
        accounts[i].deposit(dep);
        cout << "after deposit"<<endl;
        accounts[i].display();

        
        double wit;
        cout << " amount to withdraw ";
        cin >> wit;

        accounts[i].withdraw(wit);

        cout << "after withdrawal"<<endl;
        accounts[i].display();

      
        char newadd[100];
        cin.ignore(); 

        cout << "new address? ";
        cin.getline(newadd, 100);

        accounts[i].changeAddress(newadd);

        cout << "after address"<<endl;
        accounts[i].display();
        cout << endl;
    }


    int totalTransactions = 0;

    for(int i = 0; i < MAX; i++) {
        totalTransactions += accounts[i].getNumTransactions();
    }
    cout << "total transactions across all accounts " << totalTransactions << endl;

    return 0;
}
