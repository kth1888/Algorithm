#include <iostream>

#define endl "\n" // 편리하다
#define MAX 301

using namespace std;

int N;
int arr[MAX];
int DP[MAX];

int Max(int A, int B)
{
    if (A > B)
        return A;
    return B;
}

void sol()
{
    DP[1] = arr[1];                                // 첫번째 계단까지의 최댓값음 무조건 첫번째 계단 값
    DP[2] = arr[1] + arr[2];                       // 두번째 계단까지 최댓값은 무조건 첫번째 + 두번째 > 두번째 이므로
    DP[3] = Max(arr[1] + arr[3], arr[2] + arr[3]); // 세번째 계단의 최댓값은 1+3 or 2+3

    for (int i = 4; i <= N; i++)                                          // i - 2 처럼 마이너스로 범위를 지정해 주면 뒤를 넘어갈 염려가 없음
    {                                                                     // i까지의 최댓값은 i의 두번째 뒤의 계단부터 오는 것 or i의 세번째 뒤의 계단부터 i-1, i까지 오는 것
        DP[i] = Max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]); // i-2번째에서는 i-1을 밟게 되면 i를 밟을 수 없어 최댓값이 될 수 없음
    }                                                                     // 무조건 최댓값이 i번째(마지막)을 포함하므로 i -> N이 되어도 N번째 계단을 밟은 것의 최댓값이 된다
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    sol();
    cout << DP[N] << endl;
}

// https://yabmoons.tistory.com/20