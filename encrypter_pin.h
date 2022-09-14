#ifndef _ENCRYPTER_PIN_H_
#define _ENCRYPTER_PIN_H_
#include <string>
#include <iostream>
using namespace std;
class encrypter_pin
{   
    private:
        static int hash;
    public:
        encrypter_pin() = default;
        string get_hash(string);
        virtual ~encrypter_pin() = default;
};
#endif