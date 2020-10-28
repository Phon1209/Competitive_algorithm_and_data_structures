#include <stdio.h>

// Find value B of (A*B)%C = 1 when B is not negative integer that less than C and A,C is positive integer and coprime

/*
    Time Complexity
        Query : O(log(C)) per 1 query
    Space Complexity : O(1)
*/

long long expo(long long base,long long exponent,long long mod)
{
    long long val = 1;
    long long multi = base;
    while(exponent > 0)
    {
        if(exponent%2 == 1)
        {
            val*=multi;
            val%=mod;
        }
        exponent/=2;
        multi*=multi;
        multi%=mod;
    }
    return val%mod;
}

int main()
{
    int numQuery;
    long long A,B,C;
    scanf("%d",&numQuery);
    for(int it = 1;it <= numQuery;it++)
    {
        scanf("%lld %lld",&A,&C);
        B = expo(A,C-2,C);
        printf("%lld\n",B);
    }
}
