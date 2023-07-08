#include <iostream>

bool is_first_line(int height)
{
    return height == 1;
}

bool is_last_line(int height, int H)
{
    return height == H;
}

bool is_left_frame(int width)
{
    return width == 1;
}

bool is_right_frame(int width, int W)
{
    return width == W;
}

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
                if (is_first_line(height) || is_last_line(height, H))
                {
                    std::cout << '#';
                    continue;
                }
                if (is_left_frame(width) || is_right_frame(width, W))
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
}
