#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};

vector<vector<int>> matrix;
vector<vector<int>> distance_matrix;
vector<vector<int>> visited_matrix;

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    distance_matrix[x][y] = 0;
    visited_matrix[x][y] = 1;
    pair<int, int> start = make_pair(x, y);
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        // cout << "matrix " << current.first << ", " << current.second << "visited\n";

        for (int i = 0; i < 4; i++)
        {
            int next_x = current.first + dir_x[i];
            int next_y = current.second + dir_y[i];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
            {
                pair<int, int> next = make_pair(next_x, next_y);
                if (matrix[next.first][next.second] != 0 && next != start)
                {
                    q.push(next);
                    matrix[next_x][next_y] = 0;
                    distance_matrix[next_x][next_y] = distance_matrix[current.first][current.second] + 1;
                    visited_matrix[next_x][next_y] = 1;
                }
            }
        }
    }
}

int main()
{
    int loc_x = 1001;
    int loc_y = 1001;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    matrix.assign(m, vector<int>(n));
    distance_matrix.assign(m, vector<int>(n));
    visited_matrix.assign(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2)
            {
                loc_x = i;
                loc_y = j;
            }
            visited_matrix[i][j] = 0;
        }
    }

    BFS(loc_x, loc_y);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited_matrix[i][j] == 1)
            {
                cout << distance_matrix[i][j] << ' ';
            }
            else
            {
                if (matrix[i][j] == 0)
                {
                    cout << matrix[i][j] << ' ';
                }
                else
                {
                    cout << -1 << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}