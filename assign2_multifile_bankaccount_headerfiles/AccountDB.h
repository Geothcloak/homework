#ifndef ACCOUNT_DB_H
#define ACCOUNT_DB_H

#include "BankAccount.h"

class AccountDB
{
    private:
        char bankName[31];
        BankAccount arrayBankAccount[20];
        int numberOfValidData;
    public:
        //constructors
        AccountDB();
        AccountDB(const char* fileName);

        //methods
        void print() const;
        void sortAccounts();
        int searchForAccount(const char* searchNumber) const;
        void processTransactions(const char* fileName);
};
#endif
