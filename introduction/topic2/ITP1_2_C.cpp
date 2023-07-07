#include <iostream>

int main()
{
    int a, b, c, min, mid, max;
    std::cin >> a >> b >> c;
    // abc, acb, bca, bac, cab, cba
    if (a <= b && b <= c)
    {
        min = a;
        mid = b;
        max = c;
    }
    if (a <= c && c <= b)
    {
        min = a;
        mid = c;
        max = b;
    }
    if (b <= c && c <= a)
    {
        min = b;
        mid = c;
        max = a;
    }
    if (b <= a && a <= c)
    {
        min = b;
        mid = c;
        max = a;
    }
    if (c <= a && a <= b)
    {
        min = c;
        mid = a;
        max = b;
    }
    if (c <= b && b <= a)
    {
        min = c;
        mid = b;
        max = a;
    }
    std::cout << min << " " << mid << " " << max << std::endl;
    return 0;
}