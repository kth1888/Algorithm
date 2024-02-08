// Basic Template for dynamic arrays
// EX) C:\Copy\Projects\Algorithm\Practices\Array\2738.cpp
#include <iostream>

using namespace std;

int main()
{
    int N, M;

    cin >> N, M;

    // 입력받은 N 사이즈만큼의 배열 A (세로)
    int **A = new int *[N];

    // N사이즈에 배열에 M 사이즈만큼의 배열 A (가로)
    for (int i = 0; i < N; i++)
    {
        // A의 i번째에는 새로운 M사이즈의 배열이 들어간다
        A[i] = new int[M];
        // M 사이즈의 배열에 차근차근 값 넣기
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
}