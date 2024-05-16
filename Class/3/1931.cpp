#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int cnt = 1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> b >> a;
        arr[i] = {a, b};
    }
    sort(arr, arr + N);

    int end = arr[0].first;
    for (int i = 1; i < N; i++)
    {
        if (end <= arr[i].second)
        {
            cnt++;
            end = arr[i].first;
        }
    }
    cout << cnt;
}

// https://hunidev.tistory.com/42