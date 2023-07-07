#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int min_a = -1000000;
    int max_a = 1000000;
    int min = max_a;
    int max = min_a;
    long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int current_num;
        std::cin >> current_num;

        if (current_num < min)
            min = current_num;
        if (max < current_num)
            max = current_num;
        sum += current_num;
    }
    std::cout << min << " " << max << " " << sum << std::endl;
    return 0;
}