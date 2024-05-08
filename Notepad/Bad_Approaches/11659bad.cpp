#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> numbers(N + 1);
    cin.ignore();
    string input;
    getline(cin, input);

    stringstream ss(input);
    string temp;
    int i = 1;
    while (ss >> temp)
    {
        numbers[i] = stoi(temp);
        i++;
    }

    while (M--)
    {
        int start, end;
        cin >> start >> end;

        long long int result = 0;
        for (int i = start; i <= end; i++)
        {
            result += numbers[i];
        }
        cout << result << '\n';
    }
}