#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a < b && b < c)
    {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    std::cout << "No" << std::endl;
    return 0;
}