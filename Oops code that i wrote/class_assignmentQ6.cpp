#include <iostream>
#include <string>
using namespace std;


class Rbi
{

    protected:
     
    float minInterest;

    double minBalance;

    double maxWithdrawLimit;

     public:

    Rbi() {
        minInterest = 4.0;   
        minBalance = 1000;
        maxWithdrawLimit = 50000;
    }

    virtual float getInterestRate() = 0;  

    double getMinBalance() {
        return minBalance;
    }

    double getMaxWithdrawLimit() {
        return maxWithdrawLimit;
    }

    virtual ~Rbi() {}
};


class Sbi : public Rbi {
public:
    float getInterestRate() {
        return 4.5;  
    }
};

class ICICI : public Rbi{
public:
    float getInterestRate() {
        return 5.0;
    }
};

class PNB : public Rbi {
public:
    float getInterestRate() {
        return 4.25;
    }
};


class account {
private:
    int accNo;
    double balance;
    Rbi *bank;

public:
    account(int no, double bal, Rbi *b) {
        accNo = no;
        balance = bal;
        bank = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "amount deposited " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > bank->getMaxWithdrawLimit()) {
            cout << "Withdrawal limit exceeded\n";
            return;
        }

        if (balance - amount < bank->getMinBalance()) {
            cout << "Minimum balance rule violated\n";
            return;
        }

        balance -= amount;
        cout << "withdrawl sucessfull " << balance << endl;
    }

    void calculateInterest() {
        float rate = bank->getInterestRate();
        double interest = balance * rate / 100;
        cout << "interest " << interest << endl;
    }

    void show() {
        cout << "account no " << accNo << endl;
        cout << "balance   : " << balance << endl;
    }
};


class customer {
    private:
    string name;
    account *acco;

    public:
    customer(string n, account *acc) {
        name = n;
        acco = acc;
    }

    void details() {
        cout << "\ncustomer name " << name << endl;
        account->show();

    }

};


int main()

{
    
    Rbi *bank = new Sbi();    

    account acc(101, 10000, bank);

    customer c1("ranveer", &acc);

    c1.details();


    acc.deposit(5000);

    acc.withdraw(2000);
    
    acc.calculateInterest();

    delete bank;

    return 0;
}
