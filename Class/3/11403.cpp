#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> isVisited;
vector<vector<int>> matrix;

void BFS(int start)
{
    // cout << "case " << start << '\n';
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < adj[current].size(); i++)
        {
            int next = adj[current][i];
            if (!isVisited[next])
            {
                // cout << current << " to " << next << '\n';
                q.push(next);
                isVisited[next] = true;
                matrix[start][next] = 1;
            }
        }
    }
}

int main()
{
    cin >> N;
    int a = 0;
    int b = 0;

    adj.assign(N, vector<int>(0, 0));
    isVisited.assign(N, false);
    matrix.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        int input;
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            if (input == 1)
            {
                adj[i].emplace_back(j);
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < N; i++)
    {
        BFS(i);
        isVisited.assign(N, false);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}