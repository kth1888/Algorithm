#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> isVisited;
vector<vector<int>> graph;
int count;

void DFS(int current)
{
    isVisited[current] = true;

    for (int j = 0; j < graph[current].size(); j++)
    {
        int next = graph[current][j];
        if (!isVisited[next])
        {
            DFS(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    graph.assign(N + 1, vector<int>(0, 0));
    isVisited.assign(N + 1, false);

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isVisited[i])
        {
            DFS(i);
            count++;
        }
    }
    cout << count << '\n';
}