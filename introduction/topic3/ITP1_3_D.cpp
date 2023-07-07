#include <iostream>

int main()
{
    int a, b, c, divisors = 0;
    std::cin >> a >> b >> c;
    for (int i = a; i <= b; i++)
    {
        if (c % i == 0)
            divisors++;
    }
    std::cout << divisors << std::endl;
    return 0;
}