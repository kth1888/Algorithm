// string split 같은 거 이용해서 저장한다면 어떨까..?

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string sample = "OOXXOXXOOO";

    istringstream s1(sample);

    string buffer;

    int sum = 0;

    while (getline(s1, buffer, 'X'))
    {
        int stack = 1;
        for (int i = 0; i < buffer.length(); i++)
        {
            sum += stack;
            stack++;
        }
    }
    cout << sum << '\n';
}