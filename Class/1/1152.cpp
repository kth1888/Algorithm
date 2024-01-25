#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string input;

    getline(cin, input);

    istringstream inputstream(input);

    string buffer;

    int count = 0;

    while (getline(inputstream, buffer, ' '))
    {
        if (buffer != " " && buffer != "\0")
        {
            count++;
            // cout << count << buffer << '\n';
        }
    }

    cout << count << '\n';
}

// https://howudong.tistory.com/181