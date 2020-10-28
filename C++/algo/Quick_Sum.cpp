#include <stdio.h>
#define N 100000

// Using One-based numbering
// We will define "quickSum[i]" as sum of element from element 1 to element i

/*
    Time Complexity
        Preprocessing : O(N)
        Query : O(1) per 1 query
    Space Complexity : O(N)
*/
int quickSum[N];
int main()
{
    int numInput,numQuery;
    int firstIndex,lastIndex;
    scanf("%d",&numInput);
    for(int it = 1;it <= numInput;it++)
    {
        scanf("%d",&quickSum[it]);
    }

    // Process quickSum array
    for(int it = 1;it <= numInput;it++)
    {
        // sum of element it and all elements before it
        quickSum[it] += quickSum[it-1];
    }

    scanf("%d",&numQuery);
    for(int it = 1;it <= numQuery;it++)
    {
        // Find sum between this index
        scanf("%d %d",&firstIndex,&lastIndex);

        // Sum of element i to element j = Sum of element 1 to element j - Sum of element 1 to element (i-1) = quickSum[j] - quickSum[i-1]
        printf("%d\n",quickSum[lastIndex]-quickSum[firstIndex-1]);
    }
}
