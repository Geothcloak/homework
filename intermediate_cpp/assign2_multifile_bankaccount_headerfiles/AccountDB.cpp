#include "AccountDB.h"
#include <cstring>
#include <fstream>
#include <iostream>

using std::endl;
using std::cout;
using std::ifstream;
using std::cerr;

//default constructor
AccountDB::AccountDB()
{
    strcpy(bankName, "First National Bank");
    numberOfValidData = 0;
}

//alternative constructor
AccountDB::AccountDB(const char* fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile)
    {
        cerr << "Error - unable to open input file " << fileName << endl;
        exit(1);
    }

    inFile.read((char*) this, sizeof(AccountDB));

    inFile.close();
    sortAccounts();

}

//loop through array of bank accounts and print
void AccountDB::print() const
{
    cout << "Account Listing for First National Bank" << endl;
    for(int i=0; i<20; i++)
    {
        arrayBankAccount[i].print();
        cout << endl;
    }
}

//sort accounts by account number
void AccountDB::sortAccounts()
{
    int i, j;
    BankAccount bucket;
    for (i = 1; i < numberOfValidData; i++)
    {
        bucket = arrayBankAccount[i];

        for (j = i; (j > 0) && (strcmp(arrayBankAccount[j-1].getAccountNumber(), bucket.getAccountNumber()) > 0); j--)
            arrayBankAccount[j] = arrayBankAccount[j-1];

        arrayBankAccount[j] = bucket;
    }

}

//search, look up an account by account number
int AccountDB::searchForAccount(const char* searchNumber) const
{
    int low = 0;
    int high = numberOfValidData - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (strcmp(searchNumber, arrayBankAccount[mid].getAccountNumber() )== 0)
            return mid;

        if (strcmp(searchNumber, arrayBankAccount[mid].getAccountNumber() )< 0)
            high = mid - 1;
        else
            low = mid + 1;


    }
    return -1;
}

void AccountDB::processTransactions(const char* fileName)
{
    /*
       ifstream inFile;
       char transactionDate[6]
       char accountNumber[11];
       char transactionType;
       double transactionAmount;
       bool withdrawalAccepted; 

       inFile.open("fileName");
       if (inFile.is_open){
       Read transactionDate from inFile
    // while (!inFile.eof())
    {
    Read accountNumber from inFile
    Read transactionType from inFile
    Read transactionAmount from inFile

    Print transactionDate, accountNumber, and transactionType for this transaction
    int index = searchForAccount(accountNumber);
    if (index == -2)
    Print an "account not found" error message for this transaction
    else
    {
    if (transactionType == 'D')
    {
    Call the processDeposit() method for the BankAccount object at element index of the array of BankAccountk objects, passing it the transactionAmount
    Print the updated balance for the account
    }
    else
    {
    Call the processWithdrawal() method for the BankAccount object at element index of the array of BankAccountk objects, passing it the transactionAmount.
    If the withdrawal is accepted, print the new balance for the account; otherwise, print an "insufficient funds" error message
    }
    }

    Read transactionDate from inFile
    }   


    }
    inFile.close();
    */
}
