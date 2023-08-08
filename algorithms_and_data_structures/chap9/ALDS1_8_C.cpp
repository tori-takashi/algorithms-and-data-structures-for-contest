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

Node *treeMinimum(Node *x)
{
    // 一番左の最も深いものをNodeのアドレスを返す.
    while (x->left != NIL)
    {
        x = x->left;
    }
    return x;
}

Node *treeSuccessor(Node *x)
{
    // xは削除対象
    if (x->right != NIL)
        return treeMinimum(x->right); // xの右側が存在すれば、右側の子の値が最小のNodeを返す.
    // xの右側が存在しない場合、削除対象の親をyに設定.
    Node *y = x->parent;
    // 削除対象の親が根でなく、削除対象が削除対象の親の右側にいたとき
    while (y != NIL && x == y->right)
    {
        // 親も削除対象に加える
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z)
{
    Node *y;
    Node *x;

    if (z->left == NIL || z->right == NIL)
    {
        y = z;
    }
    else
    {
        y = treeSuccessor(z);
    }

    if (y->left != NIL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NIL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NIL)
    {
        root = x;
    }
    else
    {
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }

    if (y != z)
    {
        z->key = y->key;
    }

    free(y);
}

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
        else if (com == "delete")
        {
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }
    return 0;
}