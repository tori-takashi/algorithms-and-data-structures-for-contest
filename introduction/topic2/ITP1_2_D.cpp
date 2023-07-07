#include <iostream>

int main()
{
    int W, H, x, y, r;
    bool is_left_in, is_right_in, is_top_in, is_bottom_in;
    std::cin >> W >> H >> x >> y >> r;

    is_left_in = x - r >= 0;
    is_right_in = x + r <= W;
    is_top_in = y + r <= H;
    is_bottom_in = y - r >= 0;

    if (is_left_in && is_right_in && is_top_in && is_bottom_in)
    {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    std::cout << "No" << std::endl;
    return 0;
}