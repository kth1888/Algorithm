#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    queue<int> card;
    // N , N-1 .... 3, 2, 1
    for (int i = 1; i <= N; i++)
    {
        card.push(i);
    }

    int lastnum = 999;
    while (card.front() != card.back())
    {
        queue<int> reversed;
        queue<int> temp;
        // 첫번째 카드 뽑기
        card.pop();
        // 두번째 카드 뽑기
        int second = card.front();
        // cout << "preserved : " << second << '\n';
        card.pop();
        // 역순 큐에 저장하기
        while (!card.empty())
        {
            int num = card.front();
            reversed.push(num);
            card.pop();
        }
        // 뽑아둔 두번째 카드를 역순 큐에 넣기
        reversed.push(second);

        // 다시 역순을 역으로 돌리기
        while (!reversed.empty())
        {
            int num = reversed.front();
            temp.push(num);
            reversed.pop();
        }
        swap(temp, card);

        lastnum = card.front();
    }

    cout << lastnum << '\n';
}