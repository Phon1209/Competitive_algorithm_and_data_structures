#include <stdio.h>
#define N 100000

// Using Zero-based numbering
// find size of smallest subarray that has sum more than A (Only array of positive integer)
// -1 when no such subarray
/*
    Time Complexity : O(N)
    Space Complexity : O(N)
*/
int num[N];
int main()
{
    int minSize = 1e9;
    int numInput,A;
    scanf("%d%d",&numInput,&A);
    for(int it = 0;it < numInput;it++)
    {
        scanf("%d",&num[it]);
    }
    int sm = 0,st = 0;
    for(int it = 0;it < numInput;it++)
    {
        sm += num[it];
        while(sm > A)
        {
            if(minSize > it-st+1)
            minSize = it-st+1;
            sm -= num[st];
            st++;
        }
    }
    printf("%d",minSize);
}
