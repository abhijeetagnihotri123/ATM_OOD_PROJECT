#include "Account.h"
#include <iostream>
using namespace std;


int main()
{       
    Account A{"Frank",100000};
    A.deposit(1000);
    cout<<A.get_balance()<<endl;
    A.withdraw(2000);
    cout<<A.get_balance()<<endl;
    return 0;
}