#include <iostream>
#include <algorithm>

using namespace std;

long long ans;
long long list[10000];
long long K, N;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> K >> N;

    long long maxlen = 0;

    for (int i = 0; i < K; i++)
    {
        cin >> list[i];
        maxlen = max(maxlen, list[i]);
    }

    long long left = 1, right = maxlen, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        long long result = 0;

        for (int i = 0; i < K; i++)
        {
            result += list[i] / mid;
        }

        if (result >= N)
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
}

// https://yongmemo.tistory.com/21