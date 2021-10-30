#include <iostream>
#include <stdio.h>

template <class T>
class Treap
{
private:
    class Node
    {
    public:
        T key;
        int prior;
        int count;
        Node *l, *r;

        // Constructor
        Node(int prior, T key = T()) : key(key), prior(prior), count(1), l(NULL), r(NULL) {}

        int cnt() const { return this->count; }
        void upt_cnt()
        {
            count = 1;
            if (l)
                count += l->cnt();
            if (r)
                count += r->cnt();
        }
    };
    // Typedefs
    typedef Node *node;

    // Accessors
    node &getRoot() { return root; }
    void print(node current) const
    {
        if (!current)
            return;
        print(current->l);
        std::cout << current->key << std::endl;
        print(current->r);
    }

    // Modifiers
    void split(node t, int numNode, node &l, node &r)
    {
        if (!t)
        {
            l = r = NULL;
            return;
        }
        int key = t->l->cnt();
        if (key < numNode)
            split(t->r, numNode - 1 - key, t->r, r), l = t;
        else
            split(t->l, numNode, l, t->l), r = t;
        t->upt_cnt();
    }
    void merge(node &t, node l, node r)
    {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;
        t->upt_cnt();
    }

    // Representation
    node root;

public:
    // Constructor
    Treap() : root(nullptr) {}

    // Print
    void print() const { print(root); }

    // Driver Functions
    void split(int numNode, Treap &other)
    {
        split(root, numNode, getRoot(), other.getRoot());
    }
    void merge(Treap &other)
    {
        merge(root, getRoot(), other.getRoot());
    }
    void insert(T value)
    {
        srand(time(0));
        int randomKey = rand() % 1000;
        merge(root, root, new Node(randomKey, value));
    }
};
