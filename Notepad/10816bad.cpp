#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int customsearch(int n, int nums[], int start, int end, unordered_map<int, int> &indexMap)
{
    int firstOccurrence = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == n)
        {
            firstOccurrence = mid;
            end = mid - 1; // 왼쪽 부분을 탐색하기 위해 범위를 줄임
        }
        else if (nums[mid] < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // 중복 계산을 피하기 위해 찾은 인덱스를 해시 맵에 저장
    indexMap[n] = firstOccurrence;

    return firstOccurrence;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    string input;
    getline(cin, input);

    int M;
    cin >> M;
    cin.ignore();
    string input2;
    getline(cin, input2);

    // cout << N << input << M << input2 << '\n';
    stringstream s1(input);
    int *numarr = new int[N];
    string temp;
    int i = 0;
    while (s1 >> temp)
    {
        numarr[i] = stoi(temp);
        i++;
    }

    sort(numarr, numarr + N);

    stringstream s2(input2);
    int *search = new int[M];
    string temp2;
    int j = 0;
    while (s2 >> temp2)
    {
        search[j] = stoi(temp2);
        j++;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << numarr[i] << ' ';
    // }
    // cout << '\n';

    unordered_map<int, int> indexMap;

    int *result = new int[M];
    for (int k = 0; k < M; k++)
    {
        int searcher = search[k];
        int count = 0;
        int firstindex = customsearch(searcher, numarr, 0, N - 1, indexMap);
        // cout << firstindex << ' ';

        if (firstindex != -1)
        {
            do
            {
                count++;
                firstindex++;
            } while (numarr[firstindex] == searcher);
        }

        result[k] = count;
    }

    for (int i = 0; i < M; i++)
    {
        cout << result[i];

        if (i != M - 1)
        {
            cout << ' ';
        }
    }
}