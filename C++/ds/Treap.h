struct Node
{
    int key,prior;
    int cnt=1;
    Node *l,*r;
    Node(){}
    Node(int key,int prior):key(key),prior(prior),cnt(1),l(NULL),r(NULL){}
};

typedef Node * node;


int cnt(node now)
{
    return now? now->cnt:0;
}
void upt_cnt(node t)
{
    if(t)t->cnt=1+cnt(t->l)+cnt(t->r);
}
void split(node t,int k,node &l,node &r)
{
    if(!t)
    {
        l=r=NULL;
        return;
    }
    int key=cnt(t->l);
    if(key<k)split(t->r,k-1-key,t->r,r),l=t;
    else split(t->l,k,l,t->l),r=t;
    upt_cnt(t);
}
void merge(node &t,node l,node r)
{
    if(!l or !r)t= l? l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upt_cnt(t);
}