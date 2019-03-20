#include <cstdio>
#include <vector>
#include <set>

#define MAX_V 512

using namespace std;

vector<int> graph[MAX_V];
int colors[MAX_V];
int V, E, K, N;

bool check()
{
    for (int i = 1; i <= N; i++)
    {
        int sz = graph[i].size();
        for (int j = 0; j < sz; j++)
        {
            int v = graph[i][j];
            if (colors[i] == colors[v])
                return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d %d %d", &V, &E, &K);

    for (int i = 0; i < E; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s].push_back(t);
        graph[t].push_back(s);
    }

    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        set<int> cset;
        for (int j = 1; j <= V; j++)
        {
            scanf("%d", &colors[j]);
            cset.insert(colors[j]);
        }
        if (cset.size() == K && check())
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
