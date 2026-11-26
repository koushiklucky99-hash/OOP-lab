#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;

protected:
    string holderName;

public:
    void setDetails(int acc, string name, double amount)
    {
        accountNumber = acc;
        holderName = name;
        balance = amount;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
public:
    void showAccountType()
    {
        cout << "Account Type: Savings Account" << endl;
    }
};

int main()
{
    SavingsAccount s;

    s.setDetails(101, "Rahul", 5000);
    s.deposit(2000);

    s.showAccountType();
    s.display();

    return 0;
}