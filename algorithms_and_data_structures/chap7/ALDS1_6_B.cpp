#include <iostream>

int A[100000];

int partition(int A[], int p, int r)
{
    // [p...q-1] (q-1 <= q) [q] (q < q+1) [q+1 ... r]
    // Aの末尾A[r]の値をもとに左右に分ける
    int x = A[r];
    int q = p - 1;
    for (int j = p; j < r; j++)
    {
        // jはpからr-1まで走査. 基準より小さいものを見つけたら左から順番に配置して置換.
        if (A[j] <= x)
        {
            q++;
            int tmp = A[q];
            A[q] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[q + 1];
    A[q + 1] = x;
    A[r] = tmp;
    // インデックスを返す.
    return q + 1;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
    int partition_index = partition(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i == partition_index)
        {
            std::cout << "[" << A[i] << "]";
        }
        else
        {
            std::cout << A[i];
        }
        if (i == n - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
}