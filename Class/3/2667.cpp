#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int block = 1;

int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};

vector<vector<int>> matrix;
vector<vector<int>> block_matrix;
vector<vector<int>> visited_matrix;
queue<pair<int, int>> house_loc;
vector<int> house_amount;

void BFS(int x, int y)
{
    int house_count = 0;
    queue<pair<int, int>> q;
    block_matrix[x][y] = block;
    visited_matrix[x][y] = 1;
    pair<int, int> start = make_pair(x, y);
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        // cout << "matrix " << current.first << ", " << current.second << "visited\n";
        house_count++;

        for (int i = 0; i < 4; i++)
        {
            int next_x = current.first + dir_x[i];
            int next_y = current.second + dir_y[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n)
            {
                pair<int, int> next = make_pair(next_x, next_y);
                if (matrix[next.first][next.second] != 0 && next != start)
                {
                    q.push(next);
                    matrix[next_x][next_y] = 0;
                    block_matrix[next_x][next_y] = block;
                    visited_matrix[next_x][next_y] = 1;
                }
            }
        }
    }

    block++;
    house_amount.emplace_back(house_count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    matrix.assign(n, vector<int>(n));
    block_matrix.assign(n, vector<int>(n));
    visited_matrix.assign(n, vector<int>(n));

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin, input);
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = input[j] - '0';
            visited_matrix[i][j] = 0;
            if (matrix[i][j] == 1)
            {
                house_loc.push(make_pair(i, j));
            }
            block_matrix[i][j] = 0;
        }
    }

    while (!house_loc.empty())
    {
        pair<int, int> current = house_loc.front();
        house_loc.pop();
        if (visited_matrix[current.first][current.second] == 0)
        {
            BFS(current.first, current.second);
        }
    }

    sort(house_amount.begin(), house_amount.end());

    cout << block - 1 << '\n';

    for (int i = 0; i < house_amount.size(); i++)
    {
        cout << house_amount[i] << '\n';
    }

    return 0;
}