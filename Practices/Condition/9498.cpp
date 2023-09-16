#include <iostream>

int main()
{
    int score = 0;

    std::cin >> score;

    if ((int(90) <= score) && (score <= int(100)))
    {
        std::cout << "A" << std::endl;
    }
    else if ((int(80) <= score) && (score < int(90)))
    {
        std::cout << "B" << std::endl;
    }
    else if ((int(70) <= score) && (score < int(80)))
    {
        std::cout << "C" << std::endl;
    }
    else if ((int(60) <= score) && (score < int(70)))
    {
        std::cout << "D" << std::endl;
    }
    else
    {
        std::cout << "F" << std::endl;
    }
    return 0;
}