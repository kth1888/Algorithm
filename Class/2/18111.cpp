#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int MN = 2147483647;
    int H;
    int N, M, B;
    cin >> N >> M >> B;

    cin.ignore();
    int **ground = new int *[N];

    for (int i = 0; i < N; i++)
    {
        ground[i] = new int[M];
    }

    for (int i = 0; i < N; i++)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int temp;
        int j = 0;
        while (ss >> temp)
        {
            ground[i][j] = temp;
            j++;
        }
    }

    for (int e = 0; e <= 256; e++)
    {
        int x = 0; // build
        int y = 0; // rm
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (ground[i][j] > e)
                {
                    y += ground[i][j] - e;
                }
                else if (ground[i][j] < e)
                {
                    x += e - ground[i][j];
                }
            }
        }
        if (y + B >= x)
        {
            int time = y * 2 + x;
            if (MN >= time)
            {
                MN = time;
                H = e;
            }
        }
    }
    cout << MN << ' ' << H << '\n';
}

// https://velog.io/@rhkswls98/%EB%B0%B1%EC%A4%80-18111-C-%EB%A7%88%EC%9D%B8%ED%81%AC%EB%9E%98%ED%94%84%ED%8A%B8
//  블럭을 더하고 빼는 과정을 한번에 계산해야 함