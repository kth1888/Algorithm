#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int A, B, C, D, E;

    cin >> A >> B >> C >> D >> E;
    int sum = pow(A, 2) + pow(B, 2) + pow(C, 2) + pow(D, 2) + pow(E, 2);
    int result = sum % 10;

    cout << result << '\n';
}