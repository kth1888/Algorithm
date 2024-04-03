#include <iostream>

using namespace std;

void comparator(string input)
{
    int inputlen = input.length();
    int halflen = inputlen / 2;

    if (inputlen % 2 != 0)
    {
        cout << "NO" << '\n';
    }
    else if (input[0] == ')' || input[inputlen - 1] == '(')
    {
        cout << "NO" << '\n';
    }
    else
    {
        int A = 0;
        int B = 0;
        int C = 0;
        int D = 0;

        for (int i = 0; i < halflen; i++)
        {
            if (input[i] == '(')
            {
                A++;
            }
            else
            {
                B++;
            }
        }

        for (int j = halflen; j < inputlen; j++)
        {
            if (input[j] == '(')
            {
                C++;
            }
            else
            {
                D++;
            }
        }

        int left = A + C;
        int right = B + D;

        if (left == right)
        {
            if (A < B || D < C)
            {
                cout << "NO" << '\n';
            }
            else
            {

                cout << "YES" << '\n';
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        comparator(input);
    }
}