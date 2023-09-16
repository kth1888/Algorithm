#include <iostream>

int main()
{
    int A, B;

    std::cin >> A >> B;

    std::cout.precision(10);
    std::cout << (long double)A / B << std::endl;

    return 0;
}