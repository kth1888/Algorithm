#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *numbers = new int[N];
    string input;
    cin.ignore();

    getline(cin, input);
    stringstream ss(input);
    cin.ignore();

    int M;
    cin >> M;
    int *mnumbers = new int[M];
    string minput;
    cin.ignore();

    getline(cin, minput);

    string temp;
    int i = 0;
    int minnum = 10000001;
    int maxnum = -10000001;
    while (ss >> temp)
    {
        numbers[i] = stoi(temp);
        i++;
        minnum = min(minnum, numbers[i]);
        maxnum = max(maxnum, numbers[i]);
    }

    int numrange = (maxnum - minnum) + 1;
    int *numindex = new int[numrange];
    numindex = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        numindex[numbers[i] - minnum]++;
    }

    stringstream mss(minput);

    string mtemp;
    int j = 0;
    while (mss >> mtemp)
    {
        mnumbers[j] = stoi(mtemp);
        j++;
        cout << mnumbers[j] << '\n';
    }

    int *mnumbersresult = new int[M];
    mnumbersresult = {
        0,
    };

    // comparig mnumbers[k]
    for (int k = 0; k < M; k++)
    {
        if (mnumbers[k] < minnum || mnumbers[k] > maxnum)
        {
            mnumbersresult[k] = 0;
        }
        else
        {
            mnumbersresult[k] = numindex[mnumbers[k] + 10];
        }
    }

    for (int q = 0; q < M; q++)
    {
        cout << mnumbersresult[q] << ' ';
    }
}