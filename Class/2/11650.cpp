#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool customsort(const pair<int, int> a, const pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    vector<pair<int, int>> v;
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        int y;
        cin >> x >> y;

        v.push_back(pair<int, int>(x, y));
    }

    stable_sort(v.begin(), v.end(), customsort);

    vector<pair<int, int>>::iterator iter;

    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << iter->first << ' ' << iter->second << '\n';
    }
}