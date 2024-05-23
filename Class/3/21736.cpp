#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int people = 0;
int x_pos[4] = {0, 0, 1, -1};
int y_pos[4] = {1, -1, 0, 0};
vector<vector<char>> campus;
vector<vector<bool>> isVisited;
pair<int, int> init_loc;

void meet_peoples(pair<int, int> loc)
{
    queue<pair<int, int>> q;
    q.push(loc);
    isVisited[loc.first][loc.second] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        // cout << current.first << ',' << current.second << "visited\n";

        for (int i = 0; i < 4; i++)
        {
            int next_x = current.first + x_pos[i];
            int next_y = current.second + y_pos[i];

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M) // is in range
            {
                if (campus[next_x][next_y] != 'X' && !isVisited[next_x][next_y]) // is not wall(X) and not visitied
                {
                    pair<int, int> next = make_pair(next_x, next_y);
                    if (campus[next_x][next_y] == 'P')
                    {
                        people++;
                        q.push(next);
                        isVisited[next.first][next.second] = true;
                    }
                    else if (campus[next_x][next_y] == 'O')
                    {
                        q.push(next);
                        isVisited[next.first][next.second] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    campus.assign(N, vector<char>(M));
    isVisited.assign(N, vector<bool>(M));

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            campus[i][j] = input[j];
            if (input[j] == 'I')
            {
                init_loc.first = i;
                init_loc.second = j;
            }
            isVisited[i][j] = false;
        }
    }
    // cout << "start: " << init_loc.first << ", " << init_loc.second << '\n';

    meet_peoples(init_loc);

    if (people != 0)
    {
        cout << people << '\n';
    }
    else
    {
        cout << "TT" << '\n';
    }
}

// 중복 카운팅을 방지하기 위해 방문 여부는 "큐에 넣기 전에 체크", "큐에 넣은 후 방문 처리"