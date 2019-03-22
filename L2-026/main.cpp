#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX_N 102400

using namespace std;

vector<int> tree[MAX_N];
int level[MAX_N];

int N, root;

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(root, 1));

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int u = p.first;
        level[u] = p.second;

        int sz = tree[u].size();

        for (int i = 0; i < sz; i++)
        {
            int v = tree[u][i];
            q.push(make_pair(v, p.second + 1));
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int f;
        scanf("%d", &f);

        if (f == -1)
            root = i;
        else
            tree[f].push_back(i);
    }

    bfs();

    int max_l = 1;

    for (int i = 1; i <= N; i++)
        max_l = max(max_l, level[i]);

    printf("%d\n", max_l);

    vector<int> ans;

    for (int i = 1; i <= N; i++)
        if (level[i] == max_l)
            ans.push_back(i);

    int sz = ans.size();

    for (int i = 0; i < sz; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
