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

        for (string cloth : clothtype)
        {
            for (int i = 0; i < M; i++)
            {
                if (cloth == clothes[i].first)
                {
                    count++;
                }
            }
            clothamount.push_back(count);
            count = 0;
        }

        int size = clothtype.size();

        int temp = 1;
        int sum = 0;

        for (int j = 1; j < (1 << size); j++)
        {
            for (int i = 0; i < size; i++)
            {
                if (j & (1 << i))
                {
                    // cout << clothtype[i] << ' ' << clothamount[i] << ' ';
                    temp = temp * clothamount[i];
                    // cout << temp << '\n';
                }
            }
            sum += temp;
            // cout << temp << '\n';
            temp = 1;
        }
        cout << sum << '\n';

        // cout << clothes[0].first << clothes[0].second << '\n';
    }
}