#include <iostream>

bool rec(int i, int *M, int *S, int n, int query)
{
    if (i == n)
    {
        int sum = 0;
        for (int k = 0; k < n; k++)
        {
            if (S[k])
            {
                sum += M[k];
            }
        }
        return sum == query;
    }
    bool res1 = rec(i + 1, M, S, n, query);
    if (res1)
    {
        return true;
    }
    S[i] = 1;
    bool res2 = rec(i + 1, M, S, n, query);
    if (res2)
    {
        return true;
    }
    S[i] = 0;
    return false;
}

bool canGetSum(int *M, int n, int query)
{
    int S[n] = {0};
    return rec(0, M, S, n, query);
}

int main()
{
    int n;
    std::cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }

    int q;
    std::cin >> q;
    int M[q];
    for (int i = 0; i < q; i++)
    {
        std::cin >> M[i];
    }

    for (int i = 0; i < q; i++)
    {
        if (canGetSum(A, n, M[i]))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
}