// https://www.acmicpc.net/board/view/99623
// 입력을 한꺼번에 맏는게 아니었다?

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "";
    string temp;

    int loc = 0;

    while (true)
    {
        getline(cin, temp);
        if (temp == "0 0")
        {
            break;
        }
        else
        {
            str += temp;
            str += "\n";
        }
    }

    while ((unsigned int)loc != str.length())
    {
        string nums = str.substr(loc, str.find('\n'));

        int A = stoi(nums.substr(0, nums.find(' ')));

        int B = stoi(nums.substr(nums.find(' ')));

        cout << A + B << "\n";

        loc += (nums.length() + 1);
    }

    return 0;
}
