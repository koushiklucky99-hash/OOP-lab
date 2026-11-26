#include <iostream>
#include <exception>
using namespace std;

class BankingException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Banking Error";
    }
};

class InsufficientBalance : public BankingException
{
public:
    const char* what() const noexcept override
    {
        return "Insufficient Balance!";
    }
};

class InvalidAmount : public BankingException
{
public:
    const char* what() const noexcept override
    {
        return "Invalid Amount!";
    }
};

class Bank
{
    double balance;

public:
    Bank(double b)
    {
        balance = b;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;

        cout << "Withdrawal Successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main()
{
    Bank b(5000);
    double amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try
    {
        b.withdraw(amount);
    }
    catch (const BankingException &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}