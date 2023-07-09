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
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j <= i)
            {
                break;
            }
            // std::cout << "from time: " << i << " to " << j << std::endl;
            int profit_from_time_i_to_j = R[j] - R[i];
            if (profit_from_time_i_to_j > max_profit)
            {
                max_profit = profit_from_time_i_to_j;
            }
        }
    }
    std::cout << max_profit << std::endl;
    return 0;
}