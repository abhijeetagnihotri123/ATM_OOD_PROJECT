#include "encrypter_pin.h"

std::string encrypter_pin::get_hash(std::string s)
{
    for(char &c : s)
    {
        int i = c-'0';
        i += hash;
        if(i > 9)
        {
            i -= 9;
        }
        c = char(i+48);
    }
    return s;
}
int encrypter_pin::hash = 3;

