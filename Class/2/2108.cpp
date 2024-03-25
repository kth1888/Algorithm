#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

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

        numcounter[numbers[i] + 4000]++;
    }

    // cout << maxnum << '\n';
    // cout << minnum << '\n';
    int numrange = maxnum - minnum;

    // cout << sum << '\n';

    double average = 0;
    if (sum < 0)
    {
        double rawnum = -double(sum);
        // cout << rawnum << '\n';
        rawnum = rawnum / N;
        // cout << rawnum << '\n';
        double newnum = floor(rawnum + 0.5);
        // cout << newnum << '\n';
        average = -newnum;
    }
    else
    {
        average = floor(double(sum) / N + 0.5);
    }

    sort(numbers, numbers + N);

    int median = numbers[medloc - 1];

    // 최빈값의 개수
    int modenum = -1;
    //  최빈값
    int modenumloc = -1;

    for (int i = 0; i < 8001; i++)
    {

        if (numcounter[i] != 0)
        {
            // cout << "comparing " << i - 4001 << ":" << numcounter[i] << '\n';
            if (modenum < numcounter[i])
            {
                modenum = numcounter[i];
                modenumloc = i;
            }
        }
    }

    int count = 0;
    int minmodenumloc = -1;
    for (int i = 0; i < 8001; i++)
    {
        if (modenum == numcounter[i])
        {
            if (minmodenumloc == -1)
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

    minmodenumloc -= 4000;

    cout << fixed;
    cout.precision(0);

    cout << average + 0.0 << '\n';
    cout << median << '\n';
    cout << minmodenumloc << '\n';
    cout << numrange << '\n';
}