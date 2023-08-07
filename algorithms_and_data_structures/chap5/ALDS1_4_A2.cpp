#include <iostream>

bool linearSearch(int *S, int n, int query)
{
    int i = 0;
    S[n] = query;
    while (S[i] != query)
    {
        i++;
    }
    if (i == n)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    int S[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> S[i];
    }

    int q;
    std::cin >> q;
    int T[q];
    for (int i = 0; i < q; i++)
    {
        std::cin >> T[i];
    }

    int counter = 0;
    for (int i = 0; i < q; i++)
    {
        if (linearSearch(S, n, T[i]))
        {
            counter++;
        }
    }
    std::cout << counter << std::endl;
}