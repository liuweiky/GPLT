#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX_N 102400

using namespace std;

int N;
vector<int> tree[MAX_N];
bool is_root[MAX_N];
int ansd = -1;
int ans;

void bfs()
{
    int r;

    for (int i = 1; i <= N; i++)
        if (is_root[i])
        {
            r = i;
            break;
        }

    queue<pair<int, int> > q;
    q.push(make_pair(r, 0));

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (ansd < p.second)
        {
            ansd = p.second;
            ans = p.first;
        }

        for (int i = 0; i < tree[p.first].size(); i++)
            q.push(make_pair(tree[p.first][i], p.second + 1));
    }
}

int main()
{
    fill_n(is_root, MAX_N, true);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int t;
            scanf("%d", &t);
            is_root[t] = false;
            tree[i].push_back(t);
        }
    }

    bfs();

    printf("%d", ans);

    return 0;
}
