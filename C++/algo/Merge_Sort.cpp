#include <stdio.h>
#define N 100000
int num[N];
int tmpArr[N];

// Using Zero-based numbering
// Time Complexity : O(N*log(N))
// Space Complexity : O(N)
void mergeSort(int firstIndex,int lastIndex)
{
    int mid = (firstIndex+lastIndex)/2;

    if(firstIndex == lastIndex)
    return;
    else
    {
        mergeSort(firstIndex,mid);
        mergeSort(mid+1,lastIndex);
    }

    // Assign section of array num to array tmpArr
    for(int it = firstIndex;it <= lastIndex;it++)
    {
        tmpArr[it] = num[it];
    }

    // Process array tmpArr and assign Processed array to num array
    int firstHalf = firstIndex,secondHalf = mid+1;
    for(int it = firstIndex;it <= lastIndex;it++)
    {
        if(firstHalf <= mid && secondHalf <= lastIndex)
        {
            // Need to compare between two elements
            if(tmpArr[firstHalf] <= tmpArr[secondHalf])
            {
                num[it] = tmpArr[firstHalf];
                firstHalf++;
            }
            else
            {
                num[it] = tmpArr[secondHalf];
                secondHalf++;
            }
        }
        else
        {
            // No need to compare because no element to campare
            if(firstHalf <= mid)
            {
                num[it] = tmpArr[firstHalf];
                firstHalf++;
            }
            else
            {
                num[it] = tmpArr[secondHalf];
                secondHalf++;
            }
        }
    }
}
int main()
{
    int numInput;

    scanf("%d",&numInput);
    for(int it = 0;it < numInput;it++)
    {
        scanf("%d",&num[it]);
    }

    // Sorting
    mergeSort(0,numInput-1);

    printf("Sorted array : ");
    for(int it = 0;it < numInput;it++)
    {
        printf("%d ",num[it]);
    }
}
