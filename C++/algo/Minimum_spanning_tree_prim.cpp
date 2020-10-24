#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
bool chk[maxN]; // default false
priority_queue<pair<int,int > > pq;
vector<pair<int, int>> g[maxN];
int main()
{
  int s, t, w, n, m;
  // assume that label of node is 0,1,..,n-1
  int ans = 0;
  printf("number of nodes: ");
  scanf("%d", &n);
  printf("number of edges: ");
  scanf("%d", &m);
  while (m--)
  {
    // node s -> node t  with  weight W
    scanf("%d %d %d", &s, &t, &w);
    g[s].push_back(make_pair(t, w));
    g[t].push_back(make_pair(s, w));
  }

  //assume that there is always have the edge from node 0
  // start with node 0
  pq.push({0,0});

  while (!pq.empty())
  {
    s = pq.top().second;
    w = -pq.top().first;
    pq.pop();
    if(chk[s])
        continue;
    chk[s]=1;
    ans+=w;

    for (int i = 0; i < g[s].size(); i++)
    {
      t = g[s][i].first;
      w = g[s][i].second;
      if (chk[t])
        continue;
      pq.push({-w,t});

    }
  }

  printf("ans : %d\n", ans);
}
/*
7
10
0 4 4
2 0 10
0 5 3
2 3 7
2 6 5
6 5 2
5 4 5
1 4 6
1 5 2
1 3 3

*/
