#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    getline(cin, input);

    int input_size = input.length();

    vector<string> numbers;

    vector<char> symbols;

    string number = "";

    for (int i = 0; i < input_size; i++)
    {
        if (input[i] <= 57 && input[i] >= 48)
        {
            int temp = input[i] - 48;
            number += to_string(temp);
        }
        else
        {
            symbols.emplace_back(input[i]);
            numbers.emplace_back(number);
            number = "";
        }
    }
    numbers.emplace_back(number);

    // while (!numbers.empty())
    // {
    //     cout << numbers.back() << '\n';
    //     numbers.pop_back();
    // }
    // while (!symbols.empty())
    // {
    //     cout << symbols.back() << '\n';
    //     symbols.pop_back();
    // }

    int result = stoi(numbers[0]);
    int temp = 0;
    bool isCovered = false;

    for (int i = 0; i < numbers.size() - 1; i++)
    {

        if (symbols[i] == '-')
        {
            if (!isCovered)
            {
                isCovered = !isCovered;
            }
            temp += stoi(numbers[i + 1]);
        }
        else if (symbols[i] == '+')
        {
            if (isCovered)
            {
                temp += stoi(numbers[i + 1]);
            }
            else
            {
                result += stoi(numbers[i + 1]);
            }
        }
        // cout << "try " << i << '\n';
        // cout << result << '\n';
        // cout << temp << '\n';
    }
    result -= temp;

    cout << result << '\n';
}