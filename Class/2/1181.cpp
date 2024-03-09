#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

int main()
{
    int N;
    cin >> N;
    string *input = new string[N];

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    sort(input, input + N, compare);

    for (int i = 0; i < N; i++)
    {
        if (input[i] != input[i + 1])
        {
            cout << input[i] << '\n';
        }
    }
}

// https://sirius7.tistory.com/85
// https://sirius7.tistory.com/86
//  string에서의 대소비교
// https://m.blog.naver.com/PostView.naver?blogId=syinblack&logNo=222454423586&categoryNo=11&proxyReferer=