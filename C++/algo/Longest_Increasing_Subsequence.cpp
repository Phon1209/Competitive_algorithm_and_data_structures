#include <stdio.h>
#include <vector>
#define N 100000
// Using Zero-based numbering
// LIS = Longest Increasing Subsequence
// We will define "dp[i]" as LIS of element 0 to element i

/*
    Time Complexity
        Preprocessing
            function LIS1 : O(N^2)
            function LIS2 : O(N*log(N))
        Query : O(1) per 1 query
    Space Complexity : O(N)
*/
int dp[N];
int val[N];

void LIS1(int size)
{
    for(int it = 0;it < size;it++)
    {
        //use only "element it"
        dp[it] = 1;

        // Select element that have most dp value for optimal answer
        for(int selectPos = it-1;selectPos >= 0;selectPos--)
        {
            if(dp[it] < dp[selectPos]+1 && val[it] > val[selectPos])
            {
                dp[it] = dp[selectPos]+1;
            }
        }
    }
}

void LIS2(int size)
{
    std::vector <int> tmp;
    std::vector <int>::iterator selectPos;

    for(int it = 0;it < size;it++)
    {
        selectPos = lower_bound(tmp.begin(),tmp.end(),val[it]);
        if(selectPos == tmp.end())
        {
            tmp.push_back(val[it]);
        }
        else
        {
            (*selectPos) = val[it];
        }
        dp[it] = tmp.size();
    }
}

int main()
{
    int numInput,numQuery;
    scanf("%d",&numInput);
    for(int it = 0;it < numInput;it++)
    {
        scanf("%d",&val[it]);
    }

    // Process dp and val array (Select only 1 function from 2 functions)
    LIS1(numInput);
    // LIS2(numInput);

    int ed;
    scanf("%d",&numQuery);
    for(int it = 1;it <= numQuery;it++)
    {
        // Find LIS of element 0 to element ed
        scanf("%d",&ed);
        printf("%d\n",dp[ed]);
    }
}
