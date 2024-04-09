#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int *table = new int[N];
    queue<int> answer;

    for (int i = 0; i < N; i++)
    {
        table[i] = i + 1;
    }

    int itnum = 0;
    int count = 0;
    int j = 0;
    while (j < N)
    {

        if (table[itnum] != 0) // num != 0
        {
            if (count == K - 1)
            {
                // cout << table[itnum] << ' ';
                answer.push(table[itnum]);
                table[itnum] = 0;
                j++;
                count = 0;
                if (itnum == N - 1)
                {
                    itnum = 0;
                }
                else
                {
                    itnum++;
                }
            }
            else
            {
                count++;
                if (itnum == N - 1)
                {
                    itnum = 0;
                }
                else
                {
                    itnum++;
                }
            }
        }
        else // num == 0
        {
            if (itnum == N - 1)
            {
                itnum = 0;
            }
            else
            {
                itnum++;
            }
        }
    }

    cout << '<';

    int k = 0;
    while (!answer.empty())
    {
        int temp = answer.front();
        answer.pop();
        k++;
        if (k != N)
        {
            cout << temp << ", ";
        }
        else
        {
            cout << temp;
        }
    }
    cout << '>';
}
