#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int testcase;

    cin >> testcase;

    string *result = new string[testcase];

    for (int i = 0; i < testcase; i++)
    {
        cin >> result[i];

        // cout << result[i] << '\n';

        istringstream s1(result[i]);

        string buffer;

        int sum = 0;

        while (getline(s1, buffer, 'X'))
        {
            int stack = 1;
            for (int i = 0; i < buffer.length(); i++)
            {
                sum += stack;
                stack++;
            }
        }
        cout << sum << '\n';
    }
}

// 재귀적인 방법으로 풀려고 했던 거(아까워서 남겨둠)
// int streakcounter(int num, int resultstreak, string testcase)
// {
//     int result;

//     if (testcase[num] == 'O')
//     {
//         return streakcounter(num + 1, resultstreak + 1, testcase);
//     }
//     else
//     {
//         result = resultstreak;
//         return result;
//     }
// }

// int main()
// {
//     int testcase;

//     cin >> testcase;

//     string *result = new string[testcase];

//     for (int i = 0; i < testcase; i++)
//     {
//         cin >> result[i];

//         // cout << result[i] << '\n';
//     }

//     string sample = "OOO";
//     string sample1 = "OOXXOXXOOO";

//     int samplelen = sample.length();

//     int sum = 0;

//     for (int j = 0; j < samplelen; j++)
//     {
//         if (sample[j] == 'O')
//         {
//             sum += streakcounter(j, 1, sample);
//         }
//     }

//     cout << sum << '\n';
// }