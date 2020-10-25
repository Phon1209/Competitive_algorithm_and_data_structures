#include<bits/stdc++.h>
using namespace std;
#define maxN 1000005
vector<int> v[maxN];
int deg[maxN];
queue<int> q;
int main()
{
    int n,s,t,m;
    printf("number of nodes : ");
    scanf("%d",&n);
    printf("number of edges : ");
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&s,&t);
        v[s].push_back(t);
        deg[t]++;
    }
    for(int i=0;i<n;i++)
    {
        if(deg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        printf("%d ",now);
        for(int i=0;i<v[now].size();i++)
        {
            int nxt=v[now][i];
            deg[nxt]--;
            if(deg[nxt]==0)
                q.push(nxt);
        }
    }
}
