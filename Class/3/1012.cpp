#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int M, N, K;
int ground[50][50];
int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    ground[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + xpos[i];
        int y1 = y + ypos[i];
        if (x1 < 0 || y1 < 0 || x1 >= M || y1 >= N)
            continue;
        if (ground[x1][y1] == 1)
        {
            dfs(x1, y1);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    int ans = 0;

    for (int test = 0; test < T; test++)
    {
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            ground[x][y] = 1;
        }

        for (int a = 0; a < M; a++)
        {
            for (int b = 0; b < N; b++)
            {
                if (ground[a][b] == 1)
                {
                    dfs(a, b);
                    ans++;
                }
            }
        }

        cout << ans << '\n';

        // init
        for (int i = 0; i < M; i++)
        {
            memset(ground[i], 0, sizeof(int) * N);
        }
        ans = 0;
    }
}

// https://hsdevelopment.tistory.com/221
// https://dangdangee.tistory.com/entry/%EB%B0%B1%EC%A4%80-C-1012%EB%B2%88-%EC%9C%A0%EA%B8%B0%EB%86%8D-%EB%B0%B0%EC%B6%94
// https://blockdmask.tistory.com/441