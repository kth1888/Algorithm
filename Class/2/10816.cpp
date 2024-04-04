#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        cout << upper_bound(arr, arr + N, x) - lower_bound(arr, arr + N, x) << ' ';
    }
}

// https://portable-paper.tistory.com/entry/10816-%EC%88%AB%EC%9E%90-%EC%B9%B4%EB%93%9C2-C