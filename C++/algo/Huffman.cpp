#include<bits/stdc++.h>
using namespace std;
vector<pair<char,string> > ans;
struct Node
{
    Node *l,*r;
    char val;
    Node(char v)
    {
        val=v;
        l=nullptr;
        r=nullptr;
    }
    Node(Node* left,Node* right)
    {
        l=left;
        r=right;
    }
};
void dfs(Node* now,string huff)
{
    if(now->l==nullptr)
    {
        ans.push_back({now->val,huff});
        return ;
    }
    dfs(now->l,huff+'0');
    dfs(now->r,huff+'1');
}
priority_queue<pair<int,Node*> > pq;

int main()
{
    int n,num;
    char ch;
    printf("number of symbol : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nsymbol  frequency : ");
        cin>>ch>>num;
        pq.push({-num,new Node(ch)});
    }
    Node* ch1,*ch2;
    int n1,n2;
    while(pq.size()!=1)
    {
        ch1=pq.top().second;
        n1=pq.top().first;
        pq.pop();

        ch2=pq.top().second;
        n2=pq.top().first;
        pq.pop();

        pq.push({n1+n2,new Node(ch1,ch2)});
    }

    Node* root=pq.top().second;
    pq.pop();

    // dfs to leave of binary tree
    dfs(root,"");

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        printf("%c %s\n",ans[i].first,ans[i].second.c_str());
    }
}
