#include <iostream>

int main()
{
    while (true)
    {
        int H, W;
        std::cin >> H >> W;
        if (H == 0 && W == 0)
            break;
        for (int height = 1; height <= H; height++)
        {
            for (int width = 1; width <= W; width++)
            {
                std::cout << "#";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}