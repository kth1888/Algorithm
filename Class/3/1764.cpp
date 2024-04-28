#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> name1;
    vector<string> name2;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        name1.push_back(temp);
    }

    sort(name1.begin(), name1.end());

    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;
        if (binary_search(name1.begin(), name1.end(), temp))
        {
            name2.push_back(temp);
        }
    }

    sort(name2.begin(), name2.end());

    cout << name2.size() << '\n';
    for (string name : name2)
    {
        cout << name << '\n';
    }
}

// https://www.acmicpc.net/board/view/108207