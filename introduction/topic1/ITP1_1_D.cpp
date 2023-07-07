#include <iostream>

int main()
{
    int seconds, h, h_sec, m, m_sec, s;
    std::cin >> seconds;

    h = seconds / 3600;
    h_sec = h * 3600;
    m = (seconds - h_sec) / 60;
    m_sec = m * 60;
    s = seconds - (h_sec + m_sec);

    std::cout << h << ":" << m << ":" << s << std::endl;
    return 0;
}