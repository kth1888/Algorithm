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
    vector<long long int> numbers(N + 1);

    cin.ignore();
    string input;
    getline(cin, input);

    stringstream ss(input);
    string temp;
    int i = 1;
    int sums = 0;
    numbers[0] = 0;
    while (ss >> temp)
    {
        sums += stoi(temp);
        numbers[i] = sums;
        i++;
    }

    while (M--)
    {
        int start, end;
        cin >> start >> end;

        long long int result = numbers[end] - numbers[start - 1];

        cout << result << '\n';
    }
}