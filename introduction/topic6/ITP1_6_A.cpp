#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = n; 0 < i; i--)
    {
        std::cout << a[i - 1];
        if (i - 1 != 0)
        {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}