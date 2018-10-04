#include "BankAccount.h"
#include <iostream> 
#include <cstring>
#include <string>

using std::cout;
using std::string;

//default constructor
BankAccount::BankAccount()
{
    accountNumber[0] = '\0';
    customerName[0] = '\0';
    balance = 0;
}

//alternative constructor
BankAccount::BankAccount(const char *newAccountNumber, const char *newName, double newBalance)
{
    strcpy(accountNumber, newAccountNumber);
    strcpy(customerName, newName);
    balance = newBalance;
}

//getters
const char *BankAccount::getAccountNumber() const
{
    return accountNumber;
}
const char *BankAccount::getName() const
{
    return customerName;
}

double BankAccount::getBalance() const
{
    return balance;
}

//mutators
void BankAccount::processDeposit(double amount)
{
    balance += amount;
}
bool BankAccount::processWithdrawal(double amount)
{
    if (balance >= amount)
    {
        balance -= amount; 
        return true;
    }
    else
    {
        return false;
    }
}

//print bank account information
void BankAccount::print() const
{
    string stringAccountNumber = accountNumber;
    string stringCustomerName = customerName;
    cout << " Account Number: " << stringAccountNumber; 
    cout << " Name: " << stringCustomerName;
    cout << " Balance: " << balance;
}

