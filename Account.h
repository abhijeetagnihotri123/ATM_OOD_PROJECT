#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "encrypter_pin.h"
using namespace std;

class Account:private encrypter_pin
{
    private:
        double balance;
        string Account_number; // Available in debit card matching to be done in Bank Hardware so not of any concern to us.
        string name;
        string PIN;
        string aux_pin;
    public:
        static double reserve_balance;
        static int num_accounts;
        Account(string,double);
        Account(string); //I am allowing zero balance account in my design
        void deposit(double);
        void withdraw(double);
        double get_balance(void){return this->balance;}
        string get_name(void){return this->name;}
        virtual ~Account();
        static double get_reserve_balance(){return Account::reserve_balance;}
};
#endif