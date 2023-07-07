#include <iostream>

int main()
{
    int a, b;
    char operation;

    while (true)
    {
        std::cin >> a >> operation >> b;
        switch (operation)
        {
        case '+':
            std::cout << a + b << std::endl;
            break;
        case '-':
            std::cout << a - b << std::endl;
            break;
        case '*':
            std::cout << a * b << std::endl;
            break;
        case '/':
            std::cout << a / b << std::endl;
            break;
        case '?':
            return 0;
        }
    }
}