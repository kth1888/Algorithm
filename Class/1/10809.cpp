#include <iostream>
// 백준 문제에서 memset을 사용할 때 꼭 넣자.ㅎ
#include <cstring>

using namespace std;

int main()
{
    string S;

    cin >> S;

    int indexinfo[26];

    memset(indexinfo, -1, 26 * sizeof(int));

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << indexinfo[i] << ' ' << '\n';
    // }

    int loS = S.length();

    for (int i = 0; i < loS; i++)
    {
        // cout << int(S[i]) << '\n';

        if (indexinfo[int(S[i] - 97)] == -1)
        {
            indexinfo[int(S[i] - 97)] = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << indexinfo[i] << ' ';
    }
    cout << '\n';
}