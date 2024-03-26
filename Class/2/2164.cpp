#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N;
    cin >> N;

    deque<int> card;
    // N , N-1 .... 3, 2, 1
    for (int i = 1; i <= N; i++)
    {
        card.push_back(i);
    }

    int lastnum = 1;
    while (card.size() != 1)
    {
        deque<int> reversed;
        deque<int> temp;
        // 첫번째 카드 뽑기
        card.pop_front();
        // 두번째 카드 뽑기
        int second = card.front();
        // cout << "preserved : " << second << '\n';
        card.pop_front();
        card.push_back(second);

        lastnum = card.front();
    }

    cout << lastnum << '\n';
}