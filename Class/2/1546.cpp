#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    float *testpaper = new float[N];
    float *jujakpaper = new float[N];
    string input;
    getline(cin, input);

    stringstream ss(input);

    string tmp;

    int i = 0;
    while (getline(ss, tmp, ' '))
    {
        testpaper[i] = stof(tmp);
        i++;
    }

    float temp = 0;
    for (int i = 0; i < N; i++)
    {
        if (testpaper[i] > temp)
        {
            temp = testpaper[i];
        }
    }
    int maxscore = temp;
    // cout << maxscore << '\n';

    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        jujakpaper[i] = testpaper[i] / maxscore * 100;
        sum += jujakpaper[i];
    }
    cout << float(sum / N) << '\n';
}