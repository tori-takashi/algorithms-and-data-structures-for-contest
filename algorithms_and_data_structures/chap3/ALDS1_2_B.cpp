#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int A[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    int swap_count = 0;
    for (int i = 0; i < N; i++)
    {
        int minj = 100;
        int minj_index = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < minj)
            {
                minj_index = j;
                minj = A[j];
            }
        }

        if (A[i] != A[minj_index])
        {
            int tmp = A[i];
            A[i] = A[minj_index];
            A[minj_index] = tmp;
            swap_count++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << A[i];
        if (i == N - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << swap_count << std::endl;
}