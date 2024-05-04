#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> set;
vector<bool> isVisited;
int infected = 0;

void DFS(int cur)
{
    isVisited[cur] = true;
    // cout << cur << ' ';

    for (int i = 0; i < set[cur].size(); i++)
    {
        int next = set[cur][i];
        if (!isVisited[next])
        {
            DFS(next);
            infected++;
        }
    }
}

int main()
{

    cin >> N;
    cin >> M;

    set.assign(N + 1, vector<int>(0, 0));
    isVisited.assign(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        set[a].emplace_back(b);
        set[b].emplace_back(a);
    }

    DFS(1);
    cout << infected << '\n';
}

// 1260.cpp