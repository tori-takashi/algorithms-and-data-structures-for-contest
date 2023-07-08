#include <iostream>

bool has_divisor_3(int n)
{
    return n % 3 == 0;
}

bool digit_1_is_3(int current_number)
{
    return current_number % 10 == 3;
}

bool next_digit_is_3(int current_number)
{
    return current_number / 10 == 3;
}

int remove_digit_1(int current_number)
{
    return current_number /= 10;
}

bool is_contain_3(int n)
{
    int current_number = n;
    while (current_number / 10 != 0)
    {
        if (digit_1_is_3(current_number) || next_digit_is_3(current_number))
            return true;
        current_number = remove_digit_1(current_number);
    }
    return false;
}

int main()
{
    int n, first, last;
    std::cin >> n;
    first = 3;
    last = n;

    for (int i = first; i <= last; i++)
    {
        if (has_divisor_3(i) || is_contain_3(i))
            std::cout << ' ' << i;
    }
    std::cout << std::endl;
    return 0;
}