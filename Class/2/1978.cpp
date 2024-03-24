#include <iostream>
#include <sstream>
using namespace std;

int isPrime(int num)
{
    int result = 1;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            result = 0;
            break;
        }
    }

    if (num == 1)
    {
        return 0;
    }

    return result;
}

int main()
{
    int N;
    cin >> N;
    int *numbers = new int[N];
    cin.ignore();
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    int i = 0;
    while (ss >> num)
    {
        numbers[i] = num;
        i++;
    }

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += isPrime(numbers[i]);
    }

    cout << result << '\n';
}