#include <iostream>
#include <algorithm>

using namespace std;

short main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    short maxN = 0;
    short *nums = new short[N];
    short *result = new short[N];

    for (short i = 0; i < N; i++)
    {
        cin >> nums[i];
        maxN = max(nums[i], maxN);
    }
    // cout << maxN;

    short *counting = new short[maxN + 1]();

    for (short i = 0; i < N; i++)
    {
        counting[nums[i]]++;
        // cout << counting[nums[i]] << '\n';
    }

    for (short i = 1; i < maxN + 1; i++)
    {
        counting[i] += counting[i - 1];
    }

    for (short j = N - 1; j >= 0; j--)
    {
        short value = nums[j];
        counting[value]--;
        result[counting[value]] = value;
    }

    // for (short i = 0; i < N; i++)
    // {
    //     cout << nums[i] << '\n';
    // }

    // for (short i = 0; i < maxN + 1; i++)
    // {
    //     cout << counting[i] << '\n';
    // }

    for (short i = 0; i < N; i++)
    {
        cout << result[i] << '\n';
    }
}