#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        int result;
        cin >> result;

        cout << result << '\n';
        cout << result << '\n';
        cout << result << '\n';
        cout << 0 << '\n';

        return 0;
    }

    int medloc = N / 2 + 1;
    // cout << medloc << '\n';

    int sum = 0;

    int *numbers = new int[N];
    int numcounter[8001] = {
        0,
    };

    int minnum = 4001;
    int maxnum = -4001;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
        sum += numbers[i];
        minnum = min(minnum, numbers[i]);
        maxnum = max(maxnum, numbers[i]);

        numcounter[numbers[i] + 4001]++;
    }

    cout << maxnum << '\n';
    cout << minnum << '\n';
    int numrange = maxnum - minnum;

    cout << sum << '\n';

    float average = 0;
    if (sum < 0)
    {
        float rawnum = -sum;
        // cout << rawnum << '\n';
        rawnum = rawnum / N;
        // cout << rawnum << '\n';
        float newnum = floor(rawnum + 0.5);
        // cout << newnum << '\n';
        average = -newnum;
        if (average == 0)
        {
            average = 0;
        }
    }
    else
    {
        average = floor(sum / N + 0.5);
    }

    sort(numbers, numbers + N);

    int median = numbers[medloc - 1];

    // 최빈값의 개수
    int modenum = -1;
    //  최빈값
    int modenumloc = 4001;

    for (int i = 0; i < 8001; i++)
    {

        if (numcounter[i] != 0)
        {
            //cout << "comparing " << i - 4001 << ":" << numcounter[i] << '\n';
            if (modenum < numcounter[i])
            {
                modenum = numcounter[i];
                modenumloc = i;
            }
        }
    }

    int count = 0;
    int minmodenumloc = 0;
    for (int i = 0; i < 8001; i++)
    {
        if (modenum == numcounter[i])
        {
            if (minmodenumloc == 0)
            {
                minmodenumloc = i;
            }
            count++;
        }
    }
    if (1 < count)
    {
        numcounter[minmodenumloc] = -1;
    }

    for (int i = 0; i < 8001; i++)
    {
        if (modenum == numcounter[i])
        {
            minmodenumloc = i;
            break;
        }
    }

    cout << average << '\n';
    cout << median << '\n';
    cout << minmodenumloc - 4001 << '\n';
    cout << numrange << '\n';
}