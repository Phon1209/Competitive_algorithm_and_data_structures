/*
Input
First line -> A length of string
Second line -> A string
Output
Print N line. Each line represent if you start form word form position 'ans'
to position N, You will get i'th word when sort lexicographically

    Time Complexity : O(nlog^2(n))
    Space Complexity : O(nlog(n))

*/
#include<bits/stdc++.h>
using namespace std;
char str[100005];
int order[20][100005];
vector<pair<pair<int,int>,int> >suffixCheck;
main()
{
	int len;
    scanf("%d",&len);
    scanf("%s",&str[1]);
    for(int i = 1;i <= len;i++)
    {
        suffixCheck.push_back({{str[i],0},i});
    }
    int tar=1;
    for(int i = 1;i < 20;i++)
    {
        for(int j = 0;j < suffixCheck.size();j++)
        {
            int previousSuffix=suffixCheck[j].second+tar;
            suffixCheck[j].first.second=order[i-1][previousSuffix];
        }
        sort(suffixCheck.begin(),suffixCheck.end());
        pair<int,int>ck={-1,-1};
        int curOrder=0;
        for(int j = 0;j < suffixCheck.size();j++)
        {
            if(ck!=suffixCheck[j].first)
            {
                ck=suffixCheck[j].first;
                curOrder++;
            }
            order[i][suffixCheck[j].second]=curOrder;
            suffixCheck[j].first.first=curOrder;
        }
        tar*=2;
        if(i==1)
        tar=1;
    }
    for(int i = 0;i < suffixCheck.size();i++)
    {
        printf("%d\n",suffixCheck[i].second);
    }
}
