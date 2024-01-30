#include <iostream>

using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int H, W, N;

        cin >> H >> W >> N;

        // cout << H << ' ' << W << ' ' << i << '\n';

        int Q = N / H;
        int R = N % H;

        // cout << Q << ' ' << R << '\n';
        if (R == 0)
        {

            cout << H * 100 + Q << '\n';
        }
        else
        {
            cout << R * 100 + Q + 1 << '\n';
        }
    }
}

// 나머지가 0인 경우에 대한 예외처리가 필요함
// 3 6 12
// 4 0
// 5 -> 304

// 맨 처음 방에 대한 예외처리가 필요함
//  3 6 0
//  0 0
//  300 -> 101