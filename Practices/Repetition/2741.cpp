// 실행 속도는 endl 보다 \n이 빠르니 되도록 \n을 이용하자

#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cout << i << "\n";
    }

    return 0;
}