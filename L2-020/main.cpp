#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 102400

using namespace std;

int N;
double Z, r;
vector<int> tree[MAX_N];
int mul[MAX_N];

double total = 0.0;

void dfs(int id, int level)
{
    int sz = tree[id].size();
    if (sz == 0)
    {
        total += mul[id] * Z * pow(1 - r / 100, level);
        return;
    }
    for (int i = 0; i < sz; i++)
        dfs(tree[id][i], level + 1);
}

int main()
{
    fill_n(mul, MAX_N, 1);
    scanf("%d %lf %lf", &N, &Z, &r);

    for (int i = 0; i < N; i++)
    {
        int ki;
        scanf("%d", &ki);
        if (ki == 0)
            scanf("%d", &mul[i]);
        else
        {
            int id;
            for (int j = 0; j < ki; j++)
            {
                scanf("%d", &id);
                tree[i].push_back(id);
            }
        }
    }

    dfs(0, 0);

    printf("%d", (int)total);

    return 0;
}
