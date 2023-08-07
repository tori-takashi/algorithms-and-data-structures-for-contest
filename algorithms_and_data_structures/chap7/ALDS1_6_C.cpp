#include <iostream>
#include <cstdio>

struct Card
{
    char cardType;
    int cardNumber;
};

struct Card L[100000], R[100000];

void merge(Card A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1].cardNumber = 200000000;
    R[n2].cardNumber = 200000000;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i].cardNumber <= R[j].cardNumber)
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

void mergeSort(Card A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card A[], int p, int r)
{
    // [p...q-1] (q-1 <= q) [q] (q < q+1) [q+1 ... r]
    // Aの末尾A[r]の値をもとに左右に分ける
    Card x = A[r];
    int q = p - 1;
    for (int j = p; j < r; j++)
    {
        // jはpからr-1まで走査. 基準より小さいものを見つけたら左から順番に配置して置換.
        if (A[j].cardNumber <= x.cardNumber)
        {
            q++;
            Card tmp = A[q];
            A[q] = A[j];
            A[j] = tmp;
        }
    }
    Card tmp = A[q + 1];
    A[q + 1] = x;
    A[r] = tmp;
    // インデックスを返す.
    return q + 1;
}

void quickSort(struct Card A[], int n, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(A, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, q + 1, r);
    }
}

int main()
{
    int n, i, v;
    struct Card A[100000], B[100000];
    char S[10];
    int stable = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", S, &v);
        A[i].cardType = B[i].cardType = S[0];
        A[i].cardNumber = B[i].cardNumber = v;
    }

    mergeSort(A, 0, n);
    quickSort(B, n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (A[i].cardType != B[i].cardType)
        {
            stable = 0;
        }
    }

    if (stable)
    {
        std::cout << "Stable\n";
    }
    else
    {
        std::cout << "Not stable\n";
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c %d\n", B[i].cardType, B[i].cardNumber);
    }
    return 0;
}