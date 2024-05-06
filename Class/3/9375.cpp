#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int M;

    while (N--)
    {
        cin >> M;
        vector<pair<string, string>> clothes;
        vector<string> clothtype;
        vector<int> clothamount;
        for (int i = 0; i < M; i++)
        {

            string name;
            string types;

            cin >> name >> types;

            clothes.emplace_back(types, name);
            clothtype.push_back(types);
        }

        sort(clothtype.begin(), clothtype.end());
        clothtype.erase(unique(clothtype.begin(), clothtype.end()), clothtype.end());

        int count = 0;

        int result = 1;

        for (string cloth : clothtype)
        {
            for (int i = 0; i < M; i++)
            {
                if (cloth == clothes[i].first)
                {
                    count++;
                }
            }
            count++;
            result *= count;
            count = 0;
        }
        cout << result - 1 << '\n';
    }
}

// https://www.acmicpc.net/board/view/37256
// https://sanghyu.tistory.com/78
// https://suhwanc.tistory.com/84

// https://royhelen.tistory.com/29
