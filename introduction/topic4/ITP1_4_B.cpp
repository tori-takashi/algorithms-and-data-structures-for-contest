#include <iostream>
#include <iomanip>

int main()
{
    double r;
    std::cin >> r;

    const double PI = 3.141592653589;

    double square = r * r * PI;
    double border = 2 * r * PI;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << square << " " << border << std::endl;
    return 0;
}