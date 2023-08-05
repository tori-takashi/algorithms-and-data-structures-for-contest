#include <iostream>
#include <cstdio>
#include <cstdlib>

const int stack_size = 10000;

int S[stack_size] = {0};
int sp = 0;

void initialize()
{
    sp = 0;
}

bool is_full()
{
    return sp >= stack_size - 1;
}

bool is_empty()
{
    return sp == 0;
}

void push(int value)
{
    if (is_full())
    {
        std::cout << "stack is full." << std::endl;
    }
    sp++;
    S[sp] = value;
}

int pop()
{
    if (is_empty())
    {
        std::cout << "stack is empty." << std::endl;
        return -1;
    }
    int value = S[sp];
    sp--;
    return value;
}

int main()
{
    int x;
    char s[100];

    while (scanf("%s", s) != EOF)
    {
        if (s[0] == '+')
        {
            int a = pop();
            int b = pop();
            push(a + b);
        }
        else if (s[0] == '-')
        {
            int b = pop();
            int a = pop();
            push(a - b);
        }
        else if (s[0] == '*')
        {
            int a = pop();
            int b = pop();
            push(a * b);
        }
        else
        {
            x = atoi(s);
            push(x);
        }
    }

    std::cout << pop() << std::endl;

    return 0;
}