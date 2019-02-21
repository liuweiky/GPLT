#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 512

using namespace std;

int N, M, S, D;

int graph[MAX_N][MAX_N];
bool visit[MAX_N];
int path[MAX_N];
int city_team[MAX_N];
int dis[MAX_N];
int path_num[MAX_N];
int path_team[MAX_N];

void dijkstra()
{
    int u = S;
    visit[u] = true;
    dis[u] = 0;
    path_team[u] = city_team[u];
    path_num[u] = 1;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
            {
                dis[j] = dis[u] + graph[u][j];
                path[j] = u;
                path_num[j] = path_num[u];
                path_team[j] = city_team[j] + path_team[u];
            }
            else if (!visit[j] && graph[u][j] > 0 && dis[j] == dis[u] + graph[u][j])
            {
                path_num[j] += path_num[u];
                if (path_team[j] < city_team[j] + path_team[u])
                {
                    path[j] = u;
                    path_team[j] = city_team[j] + path_team[u];
                }
            }
        }

        int min_dis = INT_MAX;
        int v = -1;

        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && min_dis > dis[j])
            {
                min_dis = dis[j];
                v = j;
            }
        }

        if (v == -1)
            return;

        visit[v] = true;
        u = v;
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, -1);
    fill_n(visit, MAX_N, false);
    fill_n(path, MAX_N, -1);
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(path_num, MAX_N, 0);
    fill_n(path_team, MAX_N, 0);

    scanf("%d %d %d %d", &N, &M, &S, &D);

    for (int i = 0; i < N; i++)
        scanf("%d", &city_team[i]);

    for (int i = 0; i < M; i++)
    {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        graph[s][t] = c;
        graph[t][s] = c;
    }

    dijkstra();

    int v = D;
    vector<int> pt;

    while(v != -1)
    {
        pt.push_back(v);
        v = path[v];
    }

    printf("%d %d\n", path_num[D], path_team[D]);

    int sz = pt.size();

    for (int i = sz - 1; i >= 0; i--)
    {
        printf("%d", pt[i]);
        if (i != 0)
            printf(" ");
    }

    return 0;
}
