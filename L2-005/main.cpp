#include <cstdio>
#include <set>

#define MAX_N 64

using namespace std;

int N, M, K;

set<int> sts[MAX_N];

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &M);
        int t;
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &t);
            sts[i].insert(t);
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        set<int>* s1, *s2;
        int com = 0, total = 0;
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        s1 = &sts[t1];
        s2 = &sts[t2];

        total = s1->size() + s2->size();

        for (set<int>::iterator it = s1->begin(); it != s1->end(); it++)
        {
            if (s2->find(*it) != s2->end())
            {
                com++;
                total--;
            }
        }
        printf("%.2f%%\n", (double) com * 100 / total);
    }

    return 0;
}
