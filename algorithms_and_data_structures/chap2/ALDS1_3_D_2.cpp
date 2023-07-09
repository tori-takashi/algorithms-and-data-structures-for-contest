#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int R[n];
    for (int t = 0; t < n; t++)
    {
        std::cin >> R[t];
    }

    int max_profit = -2147483647;
    int R_current_min = R[0];
    int current_max_profit = R[1] - R[0];
    for (int t = 0; t < n - 1; t++)
    {
        if (R_current_min > R[t])
        {
            R_current_min = R[t];
        }

        current_max_profit = R[t + 1] - R_current_min;
        if (current_max_profit > max_profit)
        {
            max_profit = current_max_profit;
        }
    }
    std::cout << max_profit << std::endl;
    return 0;
}