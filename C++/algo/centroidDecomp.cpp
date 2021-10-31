/*
Centroid decomposition
Time Complexity : O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

// number of node in current subtree
int dp[100005];

// check usage of centroid
bool cen[100005];

// collection of edge in original tree (adjacency list)
vector<int>edge[100005];

// collection of edge in centroid tree (adjacency list)
vector<int>cen_tree[100005];

// depth first search to find number of node in each subtree
void dfs(int cur,int pv)
{
    dp[cur]=1;
    for(int i = 0;i < edge[cur].size();i++)
    {
        int next=edge[cur][i];
        if(cen[next]==0 && next!=pv)
        {
            dfs(next,cur);
            dp[cur]+=dp[next];
        }
    }
}

// find node that each subtree size not greater than half of current size when delete the node
int findCentroid(int cur,int pv,int size)
{
    if(size-dp[cur]<=size/2)
    {
        int mx=0;
        for(int i = 0;i < edge[cur].size();i++)
        {
            int next=edge[cur][i];
            if(cen[next]==0 && next!=pv)
            {
                mx=max(mx,dp[next]);
            }
        }
        if(mx<=size/2)
        return cur;
    }
    else
    return 0;
    dp[cur]=1;
    int centroidNode=0;
    for(int i = 0;i < edge[cur].size();i++)
    {
        int next=edge[cur][i];
        if(cen[next]==0 && next!=pv)
        {
            int curNode=findCentroid(next,cur,size);
            if(curNode!=0)
            centroidNode=curNode;
        }
    }
    return centroidNode;
}

int centroidTree(int cur)
{
    dfs(cur,-1);
    int curSize=dp[cur];
    int centroidNode=findCentroid(cur,-1,curSize);

    // mark usage on that node and proceed to each subtree that not process yet
    cen[centroidNode]=true;
    for(int i = 0;i < edge[centroidNode].size();i++)
    {
        int go=edge[centroidNode][i];
        if(cen[go]==0)
        {
            int nextCentroid=centroidTree(go);
            cen_tree[centroidNode].push_back(nextCentroid);
            cen_tree[nextCentroid].push_back(centroidNode);
        }
    }
    return centroidNode;
}
main()
{
	int node,st,ed;
    scanf("%d",&node);
    for(int i = 1;i <= node-1;i++)
    {
        // input with edge list ({st,ed})
        scanf("%d%d",&st,&ed);
        edge[st].push_back(ed);
        edge[ed].push_back(st);
    }
    // process tree
    centroidTree(1);

    // show adjacency list of centroid tree
    for(int i = 1;i <= node;i++)
    {
        printf("%d:",i);
        for(int j = 0;j < cen_tree[i].size();j++)
        {
            printf("%d ",cen_tree[i][j]);
        }
        printf("\n");
    }
    // note that last node in vector of each node is parent of current node in centroid tree (except centroid of original tree)
}

/*
Sample test:
16
1 4
2 4
3 4
4 5
5 6
6 7
7 8
7 9
6 10
10 11
11 12
11 13
12 14
13 15
13 16
*/
