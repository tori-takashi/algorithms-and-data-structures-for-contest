#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int A[n] = {0};
    int C[2000000] = {0};
    int D[2000000] = {0};

    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
        C[A[i]]++;
    }

    int counter = 0;
    for (int i = 0; i <= 10000; i++)
    {
        counter += C[i];
        C[i] = counter;
    }

    for (int i = n - 1; 0 <= i; i--)
    {
        int number_index = C[A[i]] - 1;
        D[number_index] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << D[i];
        if (i == n - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
    return 0;
}