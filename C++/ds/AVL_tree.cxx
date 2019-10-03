class AVL
{
private:
    class Node
    {
    public:
        Node *l,*r;
        int val;
        int h;
    };
public:
    Node *root=NULL;
    Node *newnode(int key)
    {
        Node *New=new Node();
        New->val=key;
        New->l=NULL;
        New->r=NULL;
        New->h=1;
        return New;
    }
    Node *rightrotate(Node *y)
    {
        Node *x=y->l;
        y->l=x->r;
        x->r=y;
        y->h=MAXH(y)+1;
        x->h=MAXH(x)+1;
        return x;
    }
    Node *leftrotate(Node *y)
    {
        Node *x=y->r;
        Node *tmp=x->l;
        y->r=tmp;
        x->l=y;
        y->h=MAXH(y)+1;
        x->h=MAXH(x)+1;
        return x;
    }
    int MAXH(Node *now)
    {
        if(now->l==NULL && now->r==NULL)return 0;
        if(now->l==NULL)return now->r->h;
        if(now->r==NULL)return now->l->h;
        return max(now->l->h,now->r->h);
    }
    int Getbal(Node *now)
    {
        int x,y;
        x=(now->l==NULL)? 0:now->l->h;
        y=(now->r==NULL)? 0:now->r->h;
        return x-y;
    }
    /*
    Insert function is used for add node with specific key to the tree
    you must call insert(tree->root,key);
    */
    Node *insert(Node *now,int key)
    {
        int left=0,right=0;
        if(now==NULL)
        {
            return newnode(key);
        }
        if(key==now->val)return now;
        if(key<now->val)
        {
            now->l=insert(now->l,key);
        }
        else
        {
            now->r=insert(now->r,key);
        }
        now->h=MAXH(now)+1;
        int bal=Getbal(now);
        if(bal>1 && key<now->l->val)
        {
            //rotate right
            return rightrotate(now);
        }
        if(bal>1 && key>now->l->val)
        {
            //rotate left-right
            now->l=leftrotate(now->l);
            return rightrotate(now);
        }
        if(bal<-1 && key>now->r->val)
        {
            //rotate left
            return leftrotate(now);
        }
        if(bal<-1 && key<now->r->val)
        {
            //rotate right-left
            now->r=rightrotate(now->r);
            return leftrotate(now);
        }
        return now;
    }
    void Preorder(Node *now)
    {
        if(now==NULL)return;
        printf("%d ",now->val);
        Preorder(now->l);
        Preorder(now->r);
    }
    Node *getl(Node *now)
    {
        while(now->l!=NULL)
        {
            now=now->l;
        }
        return now;
    }

    /*
    Delete function is used for remove node with key from the tree
    you must call Delete(tree->root,key);
    */
    Node *Delete(Node *now,int key)
    {
        if(now==NULL)return now;
        if(key<now->val)
        {
            now->l=Delete(now->l,key);
        }
        else if(key>now->val)
        {
            now->r=Delete(now->r,key);
        }
        else
        {
            if(now->l==NULL || now->r==NULL)
            {
                Node *tmp=now;
                if(now->l==NULL && now->r==NULL) now=NULL;
                else if(now->l==NULL)            now=now->r;
                else                             now=now->l;
                delete tmp;
            }
            else
            {
                Node *tmp;
                tmp=getl(now->r);
                now->val=tmp->val;
                Delete(now->r,tmp->val);
            }
        }
        if(now==NULL)return now;
        now->h=MAXH(now)+1;
        int bal=Getbal(now);
        if(bal>1 && Getbal(now->l)>=0)
        {
            return rightrotate(now);
        }
        if(bal>1 && Getbal(now->l)<0)
        {
            now->l=leftrotate(now->l);
            return rightrotate(now);
        }
        if(bal<-1 && Getbal(now->r)<=0)
        {
            return leftrotate(now);
        }
        if(bal<-1 && Getbal(now->r)>0)
        {
            now->r=rightrotate(now->r);
            return leftrotate(now);
        }
        return now;
    }
};
/*

*/
