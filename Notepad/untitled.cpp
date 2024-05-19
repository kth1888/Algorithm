#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};
int max_date = 0;

vector<vector<int>> box;
vector<vector<int>> original_box;

void BFS(int x, int y)
{
    int time = 0;
    queue<pair<int, int>> q;
    pair<int, int> start = make_pair(x, y);
    q.push(start);

    box[x][y] = 0;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        cout << "matrix (" << current.first << ", " << current.second << ") visited\n";

        for (int i = 0; i < 4; i++)
        {
            int n_x = current.first + dir_x[i];
            int n_y = current.second + dir_y[i];
            if (n_x >= 0 && n_x < M && n_y >= 0 && n_y < N)
            {
                pair<int, int> next = make_pair(n_x, n_y);
                if (box[n_x][n_y] == 0 && box[n_x][n_y] != -1 && next != start)
                {
                    q.push(next);
                    box[n_x][n_y] = box[current.first][current.second] + 1;
                    time = box[n_x][n_y];
                    cout << time << " time" << '\n';
                }
            }
        }
    }

    max_date = max(max_date, time);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    box.assign(M, vector<int>(N));

    queue<pair<int, int>> old_tomatoes;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                pair<int, int> old = make_pair(i, j);
                old_tomatoes.push(old);
            }
        }
    }
    original_box = box;

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << box[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    while (!old_tomatoes.empty())
    {
        if (old_tomatoes.size() == 1)
        {
            cout << "tomatoe out" << '\n';
            pair<int, int> current = old_tomatoes.front();
            old_tomatoes.pop();

            BFS(current.first, current.second);
        }
        else
        {
            cout << "tomatoe out" << '\n';
            pair<int, int> current = old_tomatoes.front();
            old_tomatoes.pop();

            BFS(current.first, current.second);
            box = original_box;
            cout << max_date << " " << old_tomatoes.size() << '\n';
        }
    }

    cout << max_date << '\n';

    return 0;
}