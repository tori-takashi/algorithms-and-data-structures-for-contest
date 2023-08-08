#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k)
{
    Node *x = root;
    Node *y = NIL;
    Node *z;

    // 新規nodeを作成.
    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL)
    {
        root = z;
    }
    else
    {
        if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
}

Node *find(Node *u, int k)
{
    while (u != NIL && k != u->key)
    {
        if (k < u->key)
            u = u->left;
        else
            u = u->right;
    }
    return u;
}

void inOrder(Node *u)
{
    if (u == NIL)
        return;
    printf(" %d", u->key);
    inOrder(u->left);
    inOrder(u->right);
}

void preOrder(Node *u)
{
    if (u == NIL)
        return;
    preOrder(u->left);
    printf(" %d", u->key);
    preOrder(u->right);
}

int main()
{
    int n, i, x;
    string com;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        cin >> com;
        if (com[0] == 'f')
        {
            scanf("%d", &x);
            Node *t = find(root, x);
            if (t != NIL)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if (com == "insert")
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (com == "print")
        {
            preOrder(root);
            printf("\n");
            inOrder(root);
            printf("\n");
        }
    }
    return 0;
}