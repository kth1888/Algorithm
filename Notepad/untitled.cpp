#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore();

    int *paper = new int[N];
    int *rank = new int[N];

    for (int n = 0; n < N; n++)
    {
        rank[n] = 0;
    }

    string input;
    getline(cin, input);
    stringstream ss(input);
    string temp;

    int i = 0;
    while (ss >> temp)
    {
        int currentrank = 0;
        int current = stoi(temp);
        cout << current << '\n';
        paper[i] = current;
        for (int j = 0; j < i; j++)
        {
            if (paper[j] < current)
            {
                currentrank++;
            }
            else if (paper[j] > current)
            {
                rank[j]++;
            }
        }
        rank[i] = currentrank;
        i++;

        for (int k = 0; k < N; k++)
        {
            cout << rank[k] << ' ';
        }
        cout << '\n';
    }

    for (int k = 0; k < N; k++)
    {
        cout << rank[k] << ' ';
    }
    cout << '\n';
}