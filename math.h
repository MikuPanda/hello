#include <stdint.h>
#include "BigInt.hpp"

#ifndef math
#define math

BigInt fak (int z1)
{
    if(z1==0)
    return 1;
    
    BigInt erg=1;
    
    for(int i=1;i<=z1;i++)
    {
        erg*=i;
        
    }
    return erg;
};
double multipliziere(double z1, double z2);
double substrahiere(double z1, double z2);
double dividiere(double z1, double z2);

#endif