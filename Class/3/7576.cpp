#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};
int time = 0;
int young_tomato = 0;
int old_tomato = 0;

vector<vector<int>> box;
vector<vector<int>> box_visited;
queue<pair<int, int>> q;

void BFS()
{
    pair<int, int> current = q.front();
    q.pop();

    box_visited[current.first][current.second] = 1;

    // cout << "matrix (" << current.first << ", " << current.second << ") visited\n";
    if (box[current.first][current.second] != 1)
    {
        young_tomato--;
    }

    for (int i = 0; i < 4; i++)
    {
        int n_x = current.first + dir_x[i];
        int n_y = current.second + dir_y[i];
        if (n_x >= 0 && n_x < M && n_y >= 0 && n_y < N)
        {
            pair<int, int> next = make_pair(n_x, n_y);
            if (box[n_x][n_y] == 0 && box[n_x][n_y] != -1 && box_visited[n_x][n_y] != 1)
            {
                q.push(next);
                box[n_x][n_y] = box[current.first][current.second] + 1;
                time = box[n_x][n_y];
                // cout << time << " time" << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    box.assign(M, vector<int>(N));
    box_visited.assign(M, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                pair<int, int> old = make_pair(i, j);
                q.push(old); // 시작점을 큐에 저장
                old_tomato++;
            }
            else if (box[i][j] == 0)
            {
                young_tomato++;
            }
            box_visited[i][j] = 0;
        }
    }

    // 익을 토마토가 없으면 0
    if (young_tomato == 0 && old_tomato != 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << box[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    while (!q.empty()) // 저장한 큐를 시작점으로 BFS
    {
        BFS(); // 이후 방문할 곳은 차곡차곡 큐에 다시 쌓이게 됨
    }

    // 토마토가 다 익은 경우
    if (young_tomato == 0)
    {
        cout << time - 1 << '\n';
    }
    else // 다 익지 못한 경우
    {
        cout << -1 << '\n';
    }

    return 0;
}