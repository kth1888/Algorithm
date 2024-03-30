#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int *cards = new int[N];
    string input;

    cin.ignore();
    getline(cin, input);

    stringstream ss(input);

    string temp;

    int i = 0;
    while (ss >> temp)
    {
        cards[i] = stoi(temp);
        i++;
    }

    sort(cards, cards + N, greater<int>());

    int *case1 = new int[N];
    for (int i = 0; i < N; i++)
    {
        case1[i] = N - cards[i];
    }

    int maxnum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (i != j && j != k && i != k)
                {
                    int r1 = cards[i] + cards[j] + cards[k];
                    if (r1 <= M)
                    {
                        // cout << cards[i] << " " << cards[j] << " " << cards[k] << '\n';
                        maxnum = max(maxnum, cards[i] + cards[j] + cards[k]);
                    }
                }
            }
        }
    }

    cout << maxnum << '\n';
}