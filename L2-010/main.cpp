#include <cstdio>
#include <algorithm>

#define MAX_N 128

using namespace std;

int N, M, K;

int father[MAX_N];
bool enm[MAX_N][MAX_N];

int find_father(int a)
{
    int f = a;
    while (father[f] != f)
        f = father[f];

    while (father[a] != f)
    {
        int x = father[a];
        father[a] = f;
        a = x;
    }
    return f;
}

void un(int i, int j)
{
    father[i] = j;
}

int main()
{
    fill_n(&enm[0][0], MAX_N * MAX_N, false);
    for (int i = 0; i < MAX_N; i++)
        father[i] = i;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < M; i++)
    {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        if (d == 1)
        {
            int fs = find_father(s);
            int ft = find_father(t);
            if (fs != ft)
                un(fs, ft);
        }
        else
            enm[s][t] = enm[t][s] = true;
    }

    for (int i = 0; i < K; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        int fs = find_father(s);
        int ft = find_father(t);
        if (fs == ft && !enm[s][t])
            printf("No problem\n");
        else if (fs != ft && !enm[s][t])
            printf("OK\n");
        else if (fs == ft && enm[s][t])
            printf("OK but...\n");
        else if (fs != ft && enm[s][t])
            printf("No way\n");
    }

    return 0;
}
