#include <iostream>

using namespace std;

int main()
{
    int A, B, C;

    cin >> A >> B >> C;

    int result = A * B * C;

    string resultstr = to_string(result);
    int len = resultstr.length();

    int counter[10] = {
        0,
    };

    for (int i = 0; i < len; i++)
    {
        int purenum = resultstr[i] - 48;
        counter[purenum]++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << counter[i] << '\n';
    }
}

// https://cryptosalamander.tistory.com/6