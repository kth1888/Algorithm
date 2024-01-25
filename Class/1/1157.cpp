#include <iostream>

using namespace std;

int main()
{
    string word;

    cin >> word;

    int len = word.length();
    int alpha[26] = {
        0,
    };

    for (int i = 0; i < len; i++)
    {
        word[i] = toupper(word[i]);
        alpha[word[i] - 65] += 1;
    }

    int max = alpha[0];
    int idx = 0;

    for (int i = 1; i < 26; i++)
    {
        if (max < alpha[i])
        {
            max = alpha[i];
            idx = i;
        }
    }

    for (int i = 1; i < 26; i++)
    {
        if (idx != i && max == alpha[i])
        {
            cout << '?' << '\n';
            return 0;
        }
    }

    cout << char(idx + 65) << '\n';
}

// https://tooo1.tistory.com/321
// https://velog.io/@gogori6565/BOJC-%EB%B0%B0%EC%97%B4-%ED%8A%B9%EC%A0%95-%EA%B0%92%EC%9C%BC%EB%A1%9C-%ED%95%9C-%EB%B2%88%EC%97%90-%EC%B4%88%EA%B8%B0%ED%99%94%ED%95%98%EB%8A%94-%EB%B2%95