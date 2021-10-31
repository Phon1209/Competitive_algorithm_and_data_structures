#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> g[maxN];
int m, n, dis[maxN], s, t, w;
bool chk[maxN];
int main()
{
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
  }

  //assume that there is always have the edge from node 0
  // start with node 0
  pq.push({0, 0});

  for (int i = 1; i < n; i++)
    dis[i] = INT_MAX;

  while (!pq.empty())
  {
    s = pq.top().second;
    w = -pq.top().first;
    pq.pop();
    if (chk[s])
      continue;
    chk[s] = 1;
    for (int i = 0; i < g[s].size(); i++)
    {
      t = g[s][i].first;
      w = g[s][i].second;
      if (chk[t])
        continue;
      if (dis[t] < dis[s] + w)
        continue;
      dis[t] = dis[s] + w;
      pq.push({-dis[t], t});
    }
  }
  for(int  i=1;i<n;i++)
    printf("0 -> %d : %d\n",i,dis[i]);

}

/*
testcase
7
10
0 4 4
0 2 10
2 6 5
2 3 7
6 5 2
5 0 3
5 1 2
4 5 5
4 1 6
1 3 3

*/
