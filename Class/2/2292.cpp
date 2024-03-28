#include <iostream>

using namespace std;

int main()
{
    // 1 -> 6 -> 12 -> 18 순으로 각 단계 테두리는 6씩 증가함
    // 각 6방향이 2, 3, 4, 5, 6, 7 이라면 다음은 2+6, 3+6, ...7+6 순으로 증가함

    long long N;

    cin >> N;

    long long sum = 0; // 최대 범위
    long long count = 0;
    for (long long i = 0; sum < N; i += 6)
    {
        // cout << "max range = " << sum << '\n';
        if (N == 1)
        {
            cout << '1' << '\n';
            return 0;
        }
        if (i == 0)
        {
            sum++;
            count++;
        }
        else
        {
            sum += i;
            count++;
        }
    }
    cout << count << '\n';
}