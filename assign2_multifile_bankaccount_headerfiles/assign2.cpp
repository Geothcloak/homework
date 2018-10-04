#include <iostream>
#include "BankAccount.h"
#include "AccountDB.h"

using std::cout;
using std::endl;

int main()
{
    AccountDB accountdb("accounts");
    accountdb.print(); 

    return 0;
}
