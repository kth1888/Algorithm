#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long int> original;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore();

    string input;
    getline(cin, input);
    stringstream ss(input);
    string temp;
    while (ss >> temp)
    {
        original.emplace_back(stoll(temp));
    }
    vector<long long int> copied(original);

    sort(copied.begin(), copied.end());
    copied.erase(unique(copied.begin(), copied.end()), copied.end());

    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(copied.begin(), copied.end(), original[i]);
        cout << it - copied.begin() << ' ';
    }
}

// https://donggoolosori.github.io/2020/09/26/boj-18870/
// https://chanhuiseok.github.io/posts/algo-55/#google_vignette
// https://dydtjr1128.github.io/cpp/2019/06/04/Cpp-auto.html