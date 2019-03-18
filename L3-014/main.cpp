#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

#define MAX_N 128
#define MAX_M 128
#define MAX_STOP 10240

using namespace std;

struct edge
{
    int s, t, d;
    edge(int _s, int _t, int _d): s(_s), t(_t), d(_d) {}
};

struct prio_qnode
{
    int s, d;
    prio_qnode(int _s, int _d): s(_s), d(_d) {}
    bool operator < (const prio_qnode& rhs) const
    {
        return d > rhs.d;
    }
};

int N, M, K;

int stop_com[MAX_STOP][MAX_STOP];
vector<int> graph[MAX_STOP];
vector<edge> edges;
vector<int> paths[MAX_STOP];

int dis[MAX_STOP];
bool vis[MAX_STOP];

vector<int> best_path;
int best_transfer;

void add_edge(int s, int t, int d)
{
    edge e(s, t, d);
    edges.push_back(e);
    graph[s].push_back(edges.size() - 1);
}

void dijkstra(int u)
{
    fill_n(dis, MAX_STOP, INT_MAX);
    fill_n(vis, MAX_STOP, false);
    for (int i = 0; i < MAX_STOP; i++)
        paths[i].clear();

    dis[u] = 0;

    priority_queue<prio_qnode> q;

    q.push(prio_qnode(u, 0));

    while (!q.empty())
    {
        prio_qnode n = q.top();
        q.pop();

        int v = n.s;
        if (vis[v])
            continue;
        vis[v] = true;

        for (int i = 0; i < graph[v].size(); i++)
        {
            edge& e = edges[graph[v][i]];
            if (!vis[e.t] && dis[e.t] > dis[v] + e.d)
            {
                dis[e.t] = dis[v] + e.d;
                paths[e.t].clear();
                paths[e.t].push_back(v);
                q.push(prio_qnode(e.t, dis[e.t]));
            }
            else if (!vis[e.t] && dis[e.t] == dis[v] + e.d)
                paths[e.t].push_back(v);
        }
    }
}

void dfs(int u, int s, vector<int> p, int transfer, int com)
{
    if (u == s && best_path.size() == 0)
    {
        best_path = p;
        best_transfer = transfer;
        return;
    }

    if (u == s && p.size() < best_path.size())
    {
        best_path = p;
        best_transfer = transfer;
        return;
    }
    else if (u == s && p.size() == best_path.size() && transfer < best_transfer)
    {
        best_path = p;
        best_transfer = transfer;
        return;
    }

    int sz = paths[u].size();

    for (int i = 0; i < sz; i++)
    {
        int next_city = paths[u][i];
        p.push_back(next_city);
        dfs(next_city, s, p, com == stop_com[u][next_city] ? transfer : transfer + 1, stop_com[u][next_city]);
        p.pop_back();
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &M);
        int last = -1;
        for (int j = 0; j < M; j++)
        {
            int d;
            scanf("%d", &d);
            if (last != -1)
            {
                add_edge(last, d, 1);
                add_edge(d, last, 1);
                stop_com[last][d] = stop_com[d][last] = i + 1;
            }
            last = d;
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);

        dijkstra(s);

        if (dis[t] == INT_MAX)
            printf("Sorry, no line is available.\n");
        else
        {
            vector<int> tp;
            tp.push_back(t);

            best_path.clear();
            best_transfer = INT_MAX;

            dfs(t, s, tp, 0, -1);
            printf("%d\n", best_path.size() - 1);

            int j = best_path.size() - 1;

            int sstop = best_path[j], dstop = best_path[j - 1];
            int last_com = stop_com[sstop][dstop];

            j -= 2;

            while (j >= 0)
            {
                if (last_com != stop_com[dstop][best_path[j]])
                {
                    printf("Go by the line of company #%d from %04d to %04d.\n", last_com, sstop, dstop);
                    sstop = dstop;
                    dstop = best_path[j];
                    last_com = stop_com[sstop][dstop];
                }
                else
                    dstop = best_path[j];
                j--;
            }

            printf("Go by the line of company #%d from %04d to %04d.\n", last_com, sstop, dstop);
        }
    }

    return 0;
}
