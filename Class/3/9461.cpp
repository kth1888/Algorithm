#include <iostream>
#include <algorithm>

using namespace std;

long long int result[101];

void solve(long long int N)
{
    long long int a = 1;
    long long int b = 1;
    long long int c = 1;

    long long int f = 0;
    long long int e = 0;
    long long int d = 0;

    result[1] = 1;

    for (long long int i = 1; i <= N; i++)
    {
        // cout << "loop" << i << '\n';
        long long int tri = max(max(a, b), c);
        long long int irt = max(max(d, e), f);
        long long int maxval = max(tri, irt);

        if (tri >= irt)
        {
            if (tri == a)
            {
                e += a;
                d += a;

                a = 0;
            }
            else if (tri == b)
            {
                d += b;
                f += b;

                b = 0;
            }
            else if (tri == c)
            {
                e += c;
                f += c;

                c = 0;
            }
        }
        else
        {
            if (irt == d)
            {
                a += d;
                b += d;

                d = 0;
            }
            else if (irt == e)
            {
                a += e;
                c += e;

                e = 0;
            }
            else if (irt == f)
            {
                b += f;
                c += f;

                f = 0;
            }
        }
        result[i + 1] = maxval;
    }
    cout << result[N] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N, T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        solve(N);
    }
}

// 자료형 이새끼야 !!!!!!!!!