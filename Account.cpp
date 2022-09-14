#include "Account.h"

Account::Account(string name,double balance)
{       
    this->name = name;
    this->balance = balance;
    cout<<"Enter your 5 digit PIN\n";
    cin>>aux_pin;
    while(aux_pin.length() != 5)
    {
        cout<<"Please enter a 5 digit Pin\n";
        cin>>aux_pin;
    }
    this->PIN = get_hash(aux_pin);
    cout<<"Enter PIN again for confirmation\n";
    cin>>aux_pin;
    while(this->PIN != get_hash(aux_pin))
    {
        cout<<"PINS do not match please enter again\n";
        cin>>aux_pin;
    }
    cout<<"Hello "<<name<<" an account has been opened under your name with "<<balance<<" balance\n";
    num_accounts++;
}
Account::Account(string name)
    :Account{name,0.0}
{

}
Account::~Account()
{
    cout<<"Your Account has been closed\n";
}
void Account::deposit(double amount)
{   
    cout<<"Please Enter your PIN to deposit the amount\n";
    cin>>aux_pin;
    if(this->PIN != get_hash(aux_pin))
    {
        cout<<"Wrong Pin entered Transaction has been cancelled\n";
        return;
    }
    this->balance += amount;
    Account::reserve_balance += amount;
}
void Account::withdraw(double amount)
{
    cout<<"Please enter your PIN to withdraw\n";
    cin>>aux_pin;                                              // this should be functionality of ATM clas
    if(this->PIN != get_hash(aux_pin))
    {
        cout<<"Wrong Pin entered Transaction has been cancelled\n";
        return;
    }
    if(this->balance >= amount && Account::reserve_balance >= amount)
    {
        this->balance -= amount;
        Account::reserve_balance -= amount;
    }
    else if(this->balance >= amount && Account::reserve_balance < amount)
    {
        cout<<"Bank Currently does not have enough cast to dispence\n";
    }
    else
    {
        cout<<"Insufficient Balance\n";
    }
}
double Account::reserve_balance = 10000000;
int Account::num_accounts=0;
