#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        if (t % 2)
            cnt++;
    }

    printf("%d %d", cnt, N - cnt);

    return 0;
}
