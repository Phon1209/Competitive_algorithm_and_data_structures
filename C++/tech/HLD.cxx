#define MAX_N 100005
int heavy[MAX_N],p[20][MAX_N];
int depth[MAX_N],pos[MAX_N],head[MAX_N];
int cnt=0,base[MAX_N];
int dfs(int u)
{
    int s=1;
    int mx=0;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i].F;
        if(y==p[0][u])continue;
        depth[y]=depth[u]+1;
        p[0][y]=u;
        int cs=dfs(y);
        s+=cs;
        if(cs>mx)mx=cs,heavy[u]=y;
    }
    return s;
}
void decomp(int u,int h,int cost)
{
    head[u]=h;pos[u]=++cnt;
    base[cnt]=cost;
    if(heavy[u]!=-1)decomp(heavy[u],h,-1);
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i].F;
        if(y==heavy[u])base[pos[y]]=v[u][i].S;
        if(y==heavy[u] || p[0][u]==y)continue;
        decomp(y,y,v[u][i].S);
    }
}
int query_up(int l,int r)
{
    if(l==r)return 0;
    int ans=-1;
    while(1)
    {
        if(head[l]==head[r])
        {
            if(l==r)break;
            ans=max(ans,tree->query(pos[r]+1,pos[l])); // change for another prob
            break;
        }
        ans=max(ans,tree->query(pos[head[l]],pos[l])); // change for another prob
        l=p[0][head[l]];
    }
    return ans;
}
int query(int l,int r)
{
    int lca=LCA(l,r);
    return max(query_up(l,lca),query_up(r,lca)); // change for another prob
}