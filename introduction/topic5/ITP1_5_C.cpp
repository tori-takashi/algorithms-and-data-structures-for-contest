#include <iostream>

bool is_odd(int number)
{
    return number % 2 == 1;
}

bool is_even(int number)
{
    return number % 2 == 0;
}

bool is_odd_y(int y)
{
    return is_odd(y);
}

bool is_even_y(int y)
{
    return is_even(y);
}

bool is_odd_x(int x)
{
    return is_odd(x);
}

bool is_even_x(int x)
{
    return is_even(x);
}

int main()
{
    while (true)
    {
        int H, W;
        std::cin >> H >> W;
        if (H == 0 && W == 0)
        {
            break;
        }
        for (int y = 1; y <= H; y++)
        {
            for (int x = 1; x <= W; x++)
            {
                if ((is_odd_y(y) && is_odd_x(x)) || (is_even_y(y) && is_even_x(x)))
                {
                    std::cout << '#';
                    continue;
                }
                std::cout << '.';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}