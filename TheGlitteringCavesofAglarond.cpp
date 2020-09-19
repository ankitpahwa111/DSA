#include <bits/stdtr1c++.h>
using namespace std;

void fuckThisArray(int *a, int size, int attempts, int N)
{
    sort(a, a + size, less<int>());
    int index = 0;
    while (attempts > 0 and index < size and (N - *a) > *a)
    {
        *a = N - *a;
        index++;
        attempts--;
    }
    if (attempts != 0 and attempts % 2 == 1)
    {
        auto it = min_element(a, a + size);
        *it = N - *it;
    }
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res += a[i];
    }
    cout << res << endl;
}

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case)
    {
        int M, N;
        cin >> M >> N;
        char Matrix[55][55];
        int attempts;
        cin >> attempts;
        int lit_bulbs[10000]{0};
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Matrix[i][j];
                if (Matrix[i][j] == '*')
                    lit_bulbs[i]++;
            }
        }
        fuckThisArray(lit_bulbs, M, attempts, N);
        test_case--;
    }
}