#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

//*****************************************************************
//FILE:      BankAccount.h
// AUTHOR:    your name
// LOGON ID:  your z-ID
// DUE DATE:  due date of assignment
// 
// PURPOSE:   Contains the declaration for the BankAccount class.
//*****************************************************************

class BankAccount
{
    private:
        char accountNumber[11];
        char customerName[21];
        double balance;
    public:
        //constructors
        BankAccount();
        BankAccount(const char*, const char*, double);

        //accessor methods
        const char* getAccountNumber() const;
        const char* getName() const;
        double getBalance() const;
        //mutator methods
        void processDeposit(double);
        bool processWithdrawal(double);
        //output methods
        void print() const;
};
#endif
