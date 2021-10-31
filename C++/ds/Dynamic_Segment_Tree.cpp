/*
Input q query
type 1 : push back integer A to vector
type 2 : find sum of all elements in vector with value in [left,right]

Time Complexity     O(log(bound(A))) per update/query
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class DynamicSegmentTree
{

private:
    class Node
    {
    public:
        T value;
        Node *l, *r;
        int start, end;
        Node(int start, int end, T val = T()) : value(val), l(nullptr), r(nullptr), start(start), end(end) {}
        void calculate()
        {
            value = (l) ? l->value : T();
            if (r)
                value += r->value;
        }
    };

    // Modifiers
    void update(Node *cur, int position, T value)
    {
        if (cur->start == cur->end)
        {
            cur->value += value;
            return;
        }
        int mid = (cur->start + cur->end) / 2;
        if (mid >= position)
        {
            if (!cur->l)
                cur->l = new Node(cur->start, mid, 0);
            update(cur->l, position, value);
        }
        else
        {
            if (!cur->r)
                cur->r = new Node(mid + 1, cur->end, 0);
            update(cur->r, position, value);
        }
        cur->calculate();
    }

    T query(Node *cur, int left, int right)
    {
        if (cur == NULL || cur->start > right || cur->end < left)
            return T();
        if (cur->start >= left && cur->end <= right)
            return cur->value;
        return query(cur->l, left, right) + query(cur->r, left, right);
    }

    // Typedefs
    typedef Node *node;

    // Representation
    Node *root;

public:
    // Constructors
    DynamicSegmentTree(int min, int max)
    {
        root = new Node(min, max);
    }

    // Modifiers
    void update(int position, T value)
    {
        update(root, position, value);
    }
    T query(int left, int right)
    {
        return query(root, left, right);
    }
};
main()
{
    int numQuery;
    DynamicSegmentTree<long long> tree(0, 2e9);
    scanf("%d", &numQuery);
    int type, number, left, right;
    for (int i = 1; i <= numQuery; i++)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d", &number);
            tree.update(number, 1);
        }
        else
        {
            scanf("%d%d", &left, &right);
            cout << tree.query(left, right) << endl;
        }
    }
}
