#include <iostream>
#include <queue>

using namespace std;

int loc[200000] = {
    // 방문 여부 확인 및 시간 기록을 동시에 해결
    0, // 0 = 방문하지 않음 // 1+ ~ 방문 시간
};
int N, K;

bool isValid(int x)
{
    if (0 <= x && x < 200000)
    {
        if (loc[x] == 0)
        {
            return true;
        }
    }
    return false;
}

void BFS(int N)
{
    queue<int> q;
    q.push(N); // 방문해야 할 노드
    while (!q.empty())
    {
        int x = q.front();
        q.pop(); // 방문 대기 순서대로 방문

        if (x == K) // 목적지까지 방문했다면 종료
        {
            cout << loc[K] << '\n';
            break;
        }

        if (isValid(x + 1)) // x+1 노드를 방문할 수 있는 경우
        {
            q.push(x + 1);           // 방문해야 할 리스트에 등록
            loc[x + 1] = loc[x] + 1; // 방문 시간 기록
        }

        if (isValid(x - 1)) // x-1 노드를 방문할 수 있는 경우
        {
            q.push(x - 1);           // 방문해야 할 리스트에 등록
            loc[x - 1] = loc[x] + 1; // 방문 시간 기록
        }

        if (isValid(x * 2)) // x*2 노드를 방문할 수 있는 경우
        {
            q.push(x * 2);           // 방문해야 할 리스트에 등록
            loc[x * 2] = loc[x] + 1; // 방문 시간 기록
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    BFS(N);

    return 0;
}

// https://pomo.co.kr/109

// 5 to 17
/*
1. x = 5, 5 to queue
2. pop 5(visit) and check 5 to 4, 6, 10
3. 4, 6, 10 available -> push to queue and record the time(time +1, and also visited)
4. visit 4, 6 (can check all path times)
5. visit 10 and check 9 available + record time (2)
6. visit 9 and check 18 available + record time (3)
7. visit 18 and check 17 available + record time (4)
8. 17 is K => return 4\
*/