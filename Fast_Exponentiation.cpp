#include <stdio.h>

// Calculate (A^B)%C when B is not negative integer that less than 2*10^9 and A,C is positive integer

/*
    Time Complexity
        Query : O(log(B)) per 1 query
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
        scanf("%lld %lld %lld",&A,&B,&C);

        printf("%lld\n",expo(A,B,C));
    }
}
