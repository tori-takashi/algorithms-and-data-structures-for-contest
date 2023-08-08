#include <iostream>
#include <cstdio>
#define MAX 100005
#define NIL -1

struct Node
{
    int parent;
    int sibling;
    int degree;
    int left;
    int right;
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d)
{
    if (u == NIL)
        return;
    D[u] = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

int setHeight(int u)
{
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL)
        h1 = setHeight(T[u].left) + 1;
    if (T[u].right != NIL)
        h2 = setHeight(T[u].right) + 1;
    return H[u] = (h1 > h2 ? h1 : h2);
}

void print(int u)
{
    int i, child;
    printf("node :%d, ", u);
    printf("parent = %d, ", T[u].parent);
    printf("sibling = %d, ", T[u].sibling);
    printf("degree = %d, ", T[u].degree);
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);

    if (T[u].parent == NIL)
        printf("root\n");
    else if (T[u].left == NIL)
        printf("leaf\n");
    else
        printf("internal node\n");
}

int main()
{
    int i, l, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        T[i].parent = T[i].sibling = NIL;

    for (int k = 0; k < n; k++)
    {
        scanf("%d %d %d", &i, &l, &r);
        T[i].left = l;
        T[i].right = r;

        if (l != NIL)
        {
            T[l].parent = i;
            T[l].sibling = r;
        }
        if (r != NIL)
        {
            T[r].parent = i;
            T[r].sibling = l;
        }

        if (l != NIL && r != NIL)
            T[i].degree = 2;
        else if (l != NIL || r != NIL)
            T[i].degree = 1;
        else
            T[i].degree = 0;
    }

    for (int k = 0; k < n; k++)
        if (T[k].parent == NIL)
            r = i;

    setDepth(r, 0);
    setHeight(r);

    i = 0;
    while (i < n)
    {
        print(i);
        i++;
    }

    return 0;
}