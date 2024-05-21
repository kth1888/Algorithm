#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;
int num;

int recursive_binary_search(int start, int end, int num)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    else
    {
        if (v[mid] == num)
        {
            return mid;
        }
        else if (v[mid] > num)
        {
            return binary_search(start, mid - 1, num);
        }
        else //(v[mid] < num)
        {
            return binary_search(mid + 1, end, num);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> num;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << "After Sort" << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';

    int result = recursive_binary_search(0, n - 1, num);
    cout << result << '\n';
}

/*
examples
8 9
1 5 7 6 3 9 2 11


*/
// 2805