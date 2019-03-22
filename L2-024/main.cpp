#include <cstdio>
#include <algorithm>
#include <set>

#define MAX_N 10240

using namespace std;

int father[MAX_N];
int N, Q;
set<int> people;

int find_father(int a)
{
    int f = a;
    while (father[f] > 0)
        f = father[f];

    while (a != f)
    {
        int x = father[a];
        father[a] = f;
        a = x;
    }
    return f;
}

void un(int i, int j)
{
    father[i] += father[j];
    father[j] = i;
}

int main()
{
    fill_n(father, MAX_N, -1);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int k, p, last = -1;
        scanf("%d", &k);
        for (int j = 0; j < k ; j++)
        {
            scanf("%d", &p);
            people.insert(p);
            if (last == -1)
            {
                last = p;
                continue;
            }
            int fl = find_father(last);
            int fp = find_father(p);
            if (fl != fp)
                un(fl, fp);
        }
    }

    set<int> tribe;

    for (set<int>::iterator it = people.begin(); it != people.end(); it++)
    {
        int f = find_father(*it);
        tribe.insert(f);
    }

    printf("%d %d\n", people.size(), tribe.size());

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        if (find_father(s) == find_father(t))
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
