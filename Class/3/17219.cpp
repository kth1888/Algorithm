#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> passbook;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    while (N--)
    {
        string site, password;
        cin >> site >> password;

        passbook.insert(make_pair(site, password));
    }

    while (M--)
    {
        string site;
        cin >> site;
        unordered_map<string, string>::iterator it = passbook.find(site);
        cout << it->second << '\n';
    }
}