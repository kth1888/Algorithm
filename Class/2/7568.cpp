#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first && a.second < b.second;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> dungchi;

    int *rank = new int[N]();

    for (int i = 0; i < N; i++)
    {
        rank[i]++;
        int w, h;
        cin >> w >> h;
        dungchi.push_back(make_pair(w, h));
    }

    // sort(dungchi.begin(), dungchi.end(), comp);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (j != i && comp(dungchi[i], dungchi[j]))
            {
                // cout << "comparing " << i << "and" << j << '\n';
                rank[i]++;
            }
        }
        // cout << dungchi[i].first << " " << dungchi[i].second << "\n";
    }

    for (int k = 0; k < N; k++)
    {
        cout << rank[k] << ' ';
    }
}

// https://godog.tistory.com/entry/c-vector-and-pair-%EC%82%AC%EC%9A%A9