#include <iostream>

int counter = 0;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1] = 200000000;
    R[n2] = 200000000;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        counter++;
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n;
    std::cin >> n;
    int S[n] = {0};
    for (int i = 0; i < n; i++)
    {
        std::cin >> S[i];
    }
    int left = 0;
    int right = n;
    mergeSort(S, left, right);
    for (int i = 0; i < n; i++)
    {
        std::cout << S[i];
        if (i == n - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << counter << std::endl;
}