#include <iostream>

bool binarySearch(int *S, int n, int query)
{
    int left = 0;
    int right = n;
    int mid = (left + right) / 2;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (S[mid] == query)
        {
            return true;
        }
        else if (S[mid] < query)
        {
            left = mid + 1;
        }
        else if (S[mid] > query)
        {
            right = mid;
        }
    }
    return false;
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
        if (binarySearch(S, n, T[i]))
        {
            counter++;
        }
    }
    std::cout << counter << std::endl;
}