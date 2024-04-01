#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool customsort(const pair<int, string> a, const pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    vector<pair<int, string>> v;
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        v.push_back(pair<int, string>(age, name));
    }

    stable_sort(v.begin(), v.end(), customsort);

    vector<pair<int, string>>::iterator iter;

    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << iter->first << ' ' << iter->second << '\n';
    }
}

// https://stackoverflow.com/questions/61881436/c-sorting-first-and-second-of-a-vector-of-pair-at-the-same-time
// https://breakcoding.tistory.com/117
// https://leemoney93.tistory.com/66
// https://blockdmask.tistory.com/64
// https://www.acmicpc.net/board/view/119311