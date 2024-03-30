#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int *input = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    sort(input, input + N);

    for (int i = 0; i < N; i++)
    {
        cout << input[i] << '\n';
    }
}