#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, float> Result;

    Result.insert(make_pair("A+", 4.3));
    Result.insert(make_pair("A0", 4.0));
    Result.insert(make_pair("A-", 3.7));
    Result.insert(make_pair("B+", 3.3));
    Result.insert(make_pair("B0", 3.0));
    Result.insert(make_pair("B-", 2.7));
    Result.insert(make_pair("C+", 2.3));
    Result.insert(make_pair("C0", 2.0));
    Result.insert(make_pair("C-", 1.7));
    Result.insert(make_pair("D+", 1.3));
    Result.insert(make_pair("D0", 1.0));
    Result.insert(make_pair("D-", 0.7));

    string grade;

    cin >> grade;

    cout.precision(1);
    cout << fixed;
    cout << float(Result.find(grade)->second) << "\n";
}
