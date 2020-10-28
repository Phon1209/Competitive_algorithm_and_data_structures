#include <stdio.h>
#define N 100000

// Using One-based numbering
// We will define "dp[i]" as max of subarray sum from element 1 to element i (can select empty subarray)

/*
    Time Complexity
        Preprocessing : O(N)
        Query : O(1) per 1 query
    Space Complexity : O(N)
*/
int dp[N];

void maxSum(int size)
{
    int tmp = 0;
    for(int it = 1;it <= size;it++)
    {
        tmp += dp[it];
        if(tmp < 0)
        tmp = 0;
        dp[it] = dp[it-1];
        if(dp[it] < tmp)
        dp[it] = tmp;
    }
}

int main()
{
    int numInput,numQuery;
    scanf("%d",&numInput);
    for(int it = 1;it <= numInput;it++)
    {
        scanf("%d",&dp[it]);
    }

    // Process dp array
    maxSum(numInput);

    int ed;
    scanf("%d",&numQuery);
    for(int it = 1;it <= numQuery;it++)
    {
        // Find max of subarray sum from element 1 to element ed
        scanf("%d",&ed);

        printf("%d\n",dp[ed]);
    }
}
