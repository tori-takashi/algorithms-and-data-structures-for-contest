#include <iostream>
#include <iomanip>

int main()
{
    int a, b;
    std::cin >> a >> b;

    int d = a / b;
    int r = a % b;
    double f = (double)a / b;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << d << " " << r << " " << f << std::endl;
    return 0;
}