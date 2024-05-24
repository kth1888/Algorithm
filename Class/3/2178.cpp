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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    matrix.assign(m, vector<int>(n));
    distance_matrix.assign(m, vector<int>(n));
    visited_matrix.assign(m, vector<int>(n));

    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        string input;
        getline(cin, input);
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = input[j] - '0';
            visited_matrix[i][j] = 0;
        }
    }

    BFS(0, 0);

    cout << distance_matrix[m - 1][n - 1] + 1 << '\n';

    return 0;
}