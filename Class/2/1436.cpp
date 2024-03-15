#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int ncount = 0; // 몇번째 작은수인지 세 줌
    int min = 666;  // 초기 작은수

    while (ncount < N)
    {
        string strmin = to_string(min);

        if (strmin.find("666") == string::npos)
        {
            min++;
            // cout << min << '\n';
        }
        else
        {
            ncount++;
            min++;
            // cout << ncount << '\n';
        }
    }
    cout << min - 1 << '\n';
}

// 666, 1666, 2666, 3666, 4666, 5666, 6666,
// 6660, 6661, 6662, 6663, 6664, 6665, 6666, 6667, 6668, 6669,
// 7666, ....
// 스스로 규칙 찾기는 힘들고 수  하나씩 만들어서 비교?