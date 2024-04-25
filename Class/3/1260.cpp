#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> isVisited;

void DFS(int cur)
{
    isVisited[cur] = true;
    cout << cur << ' ';

    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (!isVisited[next])
        {
            DFS(next);
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    isVisited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!isVisited[next])
            {
                q.push(next);
                isVisited[next] = true;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> V;

    graph.assign(N + 1, vector<int>(0, 0));
    isVisited.assign(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }

    for (int j = 1; j <= N; j++)
    {
        sort(graph[j].begin(), graph[j].end());
    }

    DFS(V);
    cout << '\n';
    isVisited.assign(N + 1, false);
    BFS(V);
}

// https://breakcoding.tistory.com/117
// https://m42-orion.tistory.com/64?category=1011148
// https://m42-orion.tistory.com/63