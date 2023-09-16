#include <iostream>

// 10의 12승까지 계산하려면 오버플로우를 고려하여 long long을 사용해야 함

int main()
{
    long long A, B, C;

    std::cin >> A >> B >> C;
    std::cout << A + B + C << std::endl;

    return 0;
}