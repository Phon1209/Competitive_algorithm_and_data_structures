class UnionFind
{
private:
    vector<int> p;
public:
    UnionFind(int n)
    {
        p.assign(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
    }
    int findSet(int i)
    {
        return (p[i]==i)? i:(p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j)
    {
        return (findSet(i)==findSet(j));
    }
    void unionSet(int i,int j)
    {
        int x,y;
        p[findSet(i)]=findSet(j);
    }
};
struct Edge
{
    int w;
    int x,y;
    bool operator < (const Edge &a)
    {
        return w<a.w;
    }
    Edge(int x,int y,int w):x(x),y(y),w(w){}
};
vector<Edge> v;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    // n= number of Node
    // m= number of Edge
    UnionFind uf(n+5);
    while(m--)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v.emplace_back(x,y,w);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        int x,y;
        int w;
        w=v[i].w;
        x=v[i].x;
        y=v[i].y;
        if(!uf.isSameSet(x,y))
        {
            uf.unionSet(x,y);
            ans+=w;
        }
    }
    printf("%d\n",ans);
}
/*

*/
