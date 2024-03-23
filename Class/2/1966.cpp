#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int Testcase;

    cin >> Testcase;

    for (int t = 0; t < Testcase; t++)
    {

        int amount, finder;
        cin >> amount >> finder;
        cin.ignore();

        int *priority = new int[amount];

        queue<int> tempq;
        queue<int> printq;

        string input;

        getline(cin, input);

        stringstream ss(input);

        int num;
        int maxq = 0;
        int i = 0;
        while (ss >> num)
        {
            tempq.push(i + 1);
            maxq = max(maxq, num);
            printq.push(num);

            priority[i] = num;
            i++;
        }

        sort(priority, priority + amount, greater<int>());

        int maxloc = 1;
        int popcount = 0;
        while (!printq.empty())
        {
            int temp = 0;
            if (printq.front() < maxq)
            {
                // cout << tempq.front() << "th location" << '\n';
                temp = tempq.front();
                tempq.pop();
                tempq.push(temp);

                // cout << printq.front() << " is not larger than " << maxq << '\n';
                temp = printq.front();
                printq.pop();
                printq.push(temp);
                // cout << printq.back() << " is going back" << '\n';
            }
            else
            {
                // cout << tempq.front() << "th location" << '\n';

                // cout << "pop " << printq.front() << '\n';
                printq.pop();
                maxq = priority[maxloc];
                maxloc++;

                popcount++;

                if (tempq.front() == (finder + 1))
                {
                    // cout << "result" << '\n';
                    cout << popcount << '\n';
                }
                tempq.pop();
            }
        }
    }
}

/*
3 // Test case
1 0 // 1개 문서, 0번째 (맨 왼쪽) 출력 순서가 궁금함
5 // 중요도가 5인 0번째 문서의 출력 순서 -> 1
--------------------------------------------------------
4 2
1 2 3 4 // 맨 왼쪽이 맨 앞
2 3 4 1 // 1은 중요도가 4보다 낮으므로 맨 뒤로
3 4 1 2 // 2는 중요도가 4보다 낮으므로 맨 뒤로
4 1 2 3 // 3은 중요도가 4보다 낮으므로 맨 뒤로
4 // 첫번째로 출력됨
...
3 1 2 // 2 1 // 1 순으로 정리되어 출력됨
2번 자리의 문서는 3이므로 2번째로 출력됨
-> 순서가 순차적인 경우 순차적 출력
--------------------------------------------------------
6 0 // 0번 자리의 1이 언제 출력될지 구하기 -> 1' 이라 하자
1' 1 9 1 1 1
1 9 1 1 1 1'
9 1 1 1 1' 1 // 9가 첫번째로 출력됨
1 1 1 1' 1 // 나머지는 우선순위가 같으므로 순차 출력됨
2번 3번 4번 5번' 6번 이므로 5번째로 출력됨
*/

// https://itguava.tistory.com/67