#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, string> book;
unordered_map<string, int> koob;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string input;
        cin >> input;
        book.insert(make_pair(i, input));
        koob.insert(make_pair(input, i));
    }

    for (int j = 0; j < M; j++)
    {
        string input;
        cin >> input;

        if (input[0] > 48 && input[0] < 58) // number
        {
            unordered_map<int, string>::iterator it = book.find(stoi(input));
            cout << it->second << '\n';
        }
        else if (input[0] > 64 && input[0] < 91) // Capital
        {
            unordered_map<string, int>::iterator it = koob.find(input);
            cout << it->second << '\n';
        }
        else if (input[0] > 96 && input[0] < 123) // normal
        {
            unordered_map<string, int>::iterator it = koob.find(input);
            cout << it->second << '\n';
        }
    }
}