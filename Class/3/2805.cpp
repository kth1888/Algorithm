#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trees;
int N, M;

int my_search(int target)
{
    int start = 0;
    int end = trees.back();
    int result = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        long long sum = 0;

        for (int tree : trees) // 유용한 문법
        {
            if (tree > mid)
            {
                sum += (tree - mid);
            }
        }

        if (sum >= target)
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    trees.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end());
    cout << my_search(M) << '\n';
}