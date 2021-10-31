/*
Input q query
type 1 : push back integer A to vector
type 2 : find sum of all elements in vector with value in [left,right]

Time Complexity     O(log(bound(A))) per update/query
*/

#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    long long val;
    Node *l,*r;
    int start,end;
    Node(long long val,int start,int end)
    {
        this->val=val;
        this->start=start;
        this->end=end;
        this->l=NULL;
        this->r=NULL;
    }
    void calculate()
    {
        val=0;
        if(this->l!=NULL)
        val+=l->val;
        if(this->r!=NULL)
        val+=r->val;
    }
};
class DynamicSegmentTree
{
    public:
    Node *root=new Node(0,1,2e9);
    void update(Node *cur,int position)
    {
        if(cur->start==cur->end)
        {
            cur->val+=position;
            return;
        }
        int mid=(cur->start+cur->end)/2;
        if(mid>=position)
        {
            if(cur->l==NULL)
            cur->l=new Node(0,cur->start,mid);
            update(cur->l,position);
        }
        else
        {
            if(cur->r==NULL)
            cur->r=new Node(0,mid+1,cur->end);
            update(cur->r,position);
        }
        cur->calculate();
    }
    long long query(Node *cur,int left,int right)
    {
        if(cur==NULL || cur->start>right || cur->end<left)
        return 0;
        if(cur->start>=left && cur->end<=right)
        return cur->val;
        int mid=(cur->start+cur->end)/2;
        return query(cur->l,left,right)+query(cur->r,left,right);
    }
};
main()
{
	int numQuery;
    DynamicSegmentTree tree;
    scanf("%d",&numQuery);
    int type,number,left,right;
    for(int i = 1;i <= numQuery;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d",&number);
            tree.update(tree.root,number);
        }
        else
        {
            scanf("%d%d",&left,&right);
            printf("%lld\n",tree.query(tree.root,left,right));
        }
    }
}
