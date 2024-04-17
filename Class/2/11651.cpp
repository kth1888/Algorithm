#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    vector<pair<int, int>> coordinate;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        coordinate.push_back(make_pair(x, y));
    }

    sort(coordinate.begin(), coordinate.end(), compare);

    for (int i = 0; i < N; i++)
    {
        cout << coordinate[i].first << ' ' << coordinate[i].second << '\n';
    }
}