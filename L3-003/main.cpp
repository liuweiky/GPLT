#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int father[MAX_N];

vector<int> huser[MAX_N];
int N;
int fcnt[MAX_N];

int find_father(int a)
{
    int f = a;
    while (father[f] != f)
        f = father[f];
    while (father[a] != f)
    {
        int z = father[a];
        father[a] = f;
        a = z;
    }
    return f;
}

void un(int i, int j)
{
    father[i] = j;
}

int main()
{
    fill_n(fcnt, MAX_N, 0);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        father[i] = i;

    for (int u = 1; u <= N; u++)
    {
        int k;
        scanf("%d:", &k);
        for (int j = 0; j < k; j++)
        {
            int h;
            scanf("%d", &h);
            for (int i = 0; i < huser[h].size(); i++)
            {
                int v = huser[h][i];
                int fu = find_father(u);
                int fv = find_father(v);
                if (fu != fv)
                {
                    un(fu, fv);
                    break;
                }
            }
            huser[h].push_back(u);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int f = find_father(i);
        fcnt[f]++;
    }

    sort(fcnt + 1, fcnt + N + 1);
    reverse(fcnt + 1, fcnt + N + 1);

    int p = 1;
    vector<int> ans;

    while (fcnt[p] != 0)
        ans.push_back(fcnt[p++]);

    printf("%d\n", ans.size());

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
