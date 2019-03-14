#include <cstdio>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int act[MAX_N];
int N;

int main()
{
    int total = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &act[i]);
        total += act[i];
    }

    sort(act + 1, act + 1 + N);

    int mid = N / 2;

    int sum1 = 0;

    for (int i = 1; i <= mid; i++)
        sum1 += act[i];

    int sum2 = total - sum1;
    int ans1 = abs(sum1 - sum2);

    if (N % 2 == 0)
    {
        printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", N / 2, N / 2, ans1);
        return 0;
    }

    sum1 += act[mid + 1];
    sum2 = total - sum1;
    int ans2 = abs(sum1 - sum2);

    if (ans1 >= ans2)
        printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", N - mid, mid, ans1);
    else
        printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", N - mid - 1, mid + 1, ans2);

    return 0;
}
