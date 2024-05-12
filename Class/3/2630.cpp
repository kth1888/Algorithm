#include <iostream>
#include <sstream>

using namespace std;

int N;

int count_white = 0;
int count_blue = 0;

void papercounter(int start_x, int start_y, int size, int **paper)
{
    // cout << "case: " << start_x << ' ' << start_y << ' ' << size << '\n';
    int papersize = size;
    int zeros = 0;
    int ones = 0;
    for (int i = start_x; i < start_x + papersize; i++)
    {
        for (int j = start_y; j < start_y + papersize; j++)
        {
            if (paper[i][j] == 0)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }
    }
    if (zeros != 0 && ones == 0)
    {
        // cout << "white paper" << '\n';
        count_white++;
    }
    else if (zeros == 0 && ones != 0)
    {
        // cout << "blue paper" << '\n';
        count_blue++;
    }
    else
    {
        // cout << "zeros :" << zeros << ", ones :" << ones << '\n';
        papercounter(start_x, start_y, size / 2, paper);
        papercounter(start_x, start_y + size / 2, size / 2, paper);
        papercounter(start_x + size / 2, start_y, size / 2, paper);
        papercounter(start_x + size / 2, start_y + size / 2, size / 2, paper);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore();
    int **paper = new int *[N];

    for (int i = 0; i < N; i++)
    {
        paper[i] = new int[N];
        string input;
        getline(cin, input);
        stringstream ss(input);
        string temp;
        int j = 0;
        while (ss >> temp)
        {
            paper[i][j] = stoi(temp);
            j++;
        }
    }

    papercounter(0, 0, N, paper);

    cout << count_white << '\n';

    cout << count_blue << '\n';

    for (int i = 0; i < N; i++)
    {
        delete[] paper[i];
    }
    delete[] paper;
}

// https://leeeegun.tistory.com/3