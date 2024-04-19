#include <iostream>
#include <cmath>

using namespace std;

const unsigned long long r = 31;
const unsigned long long M = 1234567891;

int main()
{
    int L;
    cin >> L;

    string input;
    cin >> input;

    unsigned long long hash = 0;

    for (int i = 0; i < L; i++)
    {
        // cout << input[i] - 96 << ' ' << pow(r, i) << '\n';
        double power = pow(r, i);

        unsigned long long temp = power;
        temp = temp % M;
        unsigned long long adder = (input[i] - 96) % M;

        adder = (adder * temp) % M;

        hash += adder;
        // cout << hash << '\n';
    }

    cout << hash % M << '\n';
    return 0;
}