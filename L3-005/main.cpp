#include <cstdio>
#include <algorithm>
#include <cctype>
#include <climits>

#define MAX_N 1024
#define MAX_M 16
#define MAX_K 102400

using namespace std;

int N, M, K, DS;
int graph[MAX_N][MAX_N];

bool visit[MAX_N];
int dis[MAX_N];

void dijkstra(int u)
{
    fill_n(visit, MAX_N, false);
    fill_n(dis, MAX_N, INT_MAX);
    dis[u] = 0;

    for (int i = 0; i < N + M - 1; i++)
    {
        visit[u] = true;
        for (int j = 1; j <= M + N; j++)
        {
            if (!visit[j] && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
                dis[j] = dis[u] + graph[u][j];
        }
        int min_dis = INT_MAX;
        int v = -1;
        for (int j = 1; j <= M + N; j++)
        {
            if (!visit[j] && dis[j] < min_dis)
            {
                min_dis = dis[j];
                v = j;
            }
        }
        if (v == -1)
            return;
        u = v;
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, -1);
    scanf("%d %d %d %d", &N, &M, &K, &DS);

    for (int i = 0; i < K; i++)
    {
        int s, t, d;
        char sbuf[16], tbuf[16];
        scanf("%s %s %d", sbuf, tbuf, &d);
        if (isalpha(sbuf[0]))
        {
            sscanf(sbuf + 1, "%d", &s);
            s += N;
        }
        else
            sscanf(sbuf, "%d", &s);
        if (isalpha(tbuf[0]))
        {
            sscanf(tbuf + 1, "%d", &t);
            t += N;
        }
        else
            sscanf(tbuf, "%d", &t);
        graph[s][t] = graph[t][s] = d;
    }

    int best = -1;
    double max_min_dis = INT_MIN;
    double min_avg_dis = INT_MAX;

    for (int i = N + 1; i <= N + M; i++)
    {
        dijkstra(i);
        bool feasible = true;
        double local_avg_dis = 0, min_dis = INT_MAX;
        for (int j = 1; j <= N; j++)
        {
            if (dis[j] > DS)
            {
                feasible = false;
                break;
            }
            local_avg_dis += dis[j];
            min_dis = min(min_dis, (double) dis[j]);
        }
        if (feasible)
        {
            local_avg_dis /= N;
            if (max_min_dis < min_dis)
            {
                best = i;
                max_min_dis = min_dis;
                min_avg_dis = local_avg_dis;
            }
            else if (max_min_dis == min_dis && min_avg_dis > local_avg_dis)
            {
                best = i;
                min_avg_dis = local_avg_dis;
            }
        }
    }

    if (best == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", best - N, max_min_dis, min_avg_dis);

    return 0;
}
