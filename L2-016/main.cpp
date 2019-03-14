#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 102400

using namespace std;

struct node
{
    int father, mother;
    node () {father = mother = -1;}
};

node tree[MAX_N];
char fm[MAX_N];
int N, K;

bool vis[MAX_N];
bool flag = true;

void dfsl(int id, int level)
{
    if (level > 5)
        return;
    vis[id] = true;
    node n = tree[id];
    if (n.father != -1)
        dfsl(n.father, level + 1);
    if (n.mother != -1)
        dfsl(n.mother, level + 1);
}

void dfsr(int id, int level)
{
    if (level > 5)
        return;
    if (vis[id])
    {
        flag = false;
        return;
    }
    node n = tree[id];
    if (n.father != -1)
        dfsr(n.father, level + 1);
    if (n.mother != -1)
        dfsr(n.mother, level + 1);
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char c;
        int id, f, m;
        scanf("%d %c %d %d", &id, &c, &f, &m);
        node n;
        n.father = f;
        n.mother = m;
        fm[id] = c;
        tree[id] = n;
        fm[f] = 'M';
        fm[m] = 'F';
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        fill_n(vis, MAX_N, false);
        int lid, rid;
        scanf("%d %d", &lid, &rid);

        if (fm[lid] == fm[rid])
        {
            printf("Never Mind\n");
            continue;
        }
        flag = true;
        dfsl(lid, 1);
        dfsr(rid, 1);

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
