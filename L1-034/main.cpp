#include <cstdio>
#include <algorithm>

#define MAX_TAG 1024

using namespace std;

int mp[MAX_TAG];
int N;

int main()
{
    fill_n(mp, MAX_TAG, 0);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int k, t;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &t);
            mp[t]++;
        }
    }

    int maxx = -1;
    int best = -1;

    for (int i = 1; i <= 1000; i++)
        if (maxx <= mp[i])
        {
            maxx = mp[i];
            best = i;
        }

    printf("%d %d", best, maxx);

    return 0;
}
