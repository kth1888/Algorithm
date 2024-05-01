#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> ppl;

bool sort_rule(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    string input;
    getline(cin, input);
    stringstream ss(input);

    string temp;
    while (ss >> temp)
    {
        ppl.push_back(stoi(temp));
    }

    sort(ppl.begin(), ppl.end(), sort_rule);

    int result = 0;
    int sums = 0;

    while (!ppl.empty())
    {
        int temp = ppl.back();
        ppl.pop_back();
        sums += temp;
        result += sums;
    }

    cout << result << '\n';
}