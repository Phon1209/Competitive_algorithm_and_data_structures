#include<bits/stdc++.h>
using namespace std;
int find(char c)
{
    if(c>='0' && c<='9')return c-='0';
    if(c>='A' && c<='Z')return c-='A'+10;
    if(c>='a' && c<='z')return c-='a'+36;
}

int main()
{
    string a,b;
    cin>>a>>b;
    int mul=1;
    int x=0;
    int y=0;
    for(int i=0;i<b.size();i++)
    {
        mul*=137;
        x*=137;
        x+=find(b[i]);
    }
    queue<int> q;
    for(int i=0;i<a.size();i++)
    {
        y*=137;
        y+=find(a[i]);
        q.push(find(a[i]));
        if(q.size()>b.size())
        {
            y-=q.front()*mul;
            q.pop();
        }
        if(q.size()==b.size() && x==y)
        {
            printf("Found at %d\n",i-b.size()+1);
        }
    }
}
