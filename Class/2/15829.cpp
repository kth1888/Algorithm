#include <iostream>

using namespace std;

const unsigned long long r = 31;
const unsigned long long M = 1234567891;

unsigned long long mypow(int i)
{
    unsigned long long returnval = 1;
    for (int j = 0; j < i; j++)
    {
        returnval *= r;
        returnval = returnval % M;
    }
    return returnval % M;
}

int main()
{
    int L;
    cin >> L;

    string input;
    cin >> input;

    unsigned long long result = 0;

    for (int i = 0; i < L; i++)
    {
        unsigned long long adder = (input[i] - 96) % M;

        // (A*B)%N = () A%N * B%N ) %N

        unsigned long long pow = mypow(i);

        result += (adder * pow) % M;
    }

    cout << result % M << '\n';
}

// https://velog.io/@cse_pebb/C-pow-%ED%95%A8%EC%88%98
// pow는 double을 return 하는데, double형을 다룰 때는 정확도에 항상 주의할 것 (나머지 구할 때)
// pow 때문에 틀렸다 오버플로우가 애지간히 욕먹게 하는 점 유의
// 합동식, 해시함수