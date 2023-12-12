// https://goalsdhkdwk.tistory.com/entry/BOJ%EB%B0%B1%EC%A4%80-5597%EB%B2%88-%EA%B3%BC%EC%A0%9C-%EC%95%88-%EB%82%B4%EC%8B%A0-%EB%B6%84-cc-%ED%92%80%EC%9D%B4
//  index 로 바로 값을 박아버리기

#include <iostream>

using namespace std;

int main()
{
    int student[30];

    fill_n(student, 30, 0);

    for (int i = 0; i < 28; i++)
    {
        int input;
        cin >> input;

        student[input - 1] = input;
    }

    for (int j = 0; j < 30; j++)
    {
        if (student[j] == 0)
        {
            cout << j + 1 << '\n';
        }
    }

    return 0;
}