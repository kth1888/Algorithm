#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{

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

    int mintime = 2147483647;
    int heights[256];
    for (int i = 0; i < 256; i++)
    {
        heights[i] = 2147483647;
    }

    for (int goal = 0; goal < 256; goal++)
    {
        int time = 0;
        int capacity = B;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (goal - ground[i][j] > 0)
                {
                    int temp = goal - ground[i][j];
                    time += temp;
                    capacity -= temp;
                }
                else
                {
                    int temp = ground[i][j] - goal;
                    time += temp * 2;
                    capacity += temp;
                }
            }
        }
        if (capacity >= 0)
        {
            heights[goal] = time;
        }
    }

    for (int i = 0; i < 256; i++)
    {
        if (heights[i] != 2147483647)
        {

            mintime = min(heights[i], mintime);
        }
    }

    for (int i = 0; i < 256; i++)
    {
        if (heights[i] == mintime)
        {
            cout << mintime << ' ' << i << '\n';
        }
    }
}