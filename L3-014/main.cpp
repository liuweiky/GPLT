#include <cstdio>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 128
#define MAX_M 128
#define MAX_STOP 10240

using namespace std;

map<int, int> id2hash;
map<int, int> hash2id;

int cur_hash = 0;
int N, M, K;

int stop_com[MAX_STOP][MAX_STOP];
vector<int> graph[MAX_STOP];
vector<int> paths[MAX_STOP];

int dis[MAX_STOP];
bool vis[MAX_STOP];

vector<int> best_path;
int best_transfer;

int get_hash(int id)
{
    if (id2hash.find(id) == id2hash.end())
    {
        id2hash[id] = cur_hash;
        hash2id[cur_hash++] = id;
    }
    return id2hash[id];
}

int get_id(int h)
{
    return hash2id[h];
}

void dijkstra(int u)
{
    fill_n(dis, MAX_STOP, INT_MAX);
    fill_n(vis, MAX_STOP, false);
    for (int i = 0; i < cur_hash; i++)
        paths[i].clear();

    dis[u] = 0;

    for (int i = 0; i < cur_hash - 1; i++)
    {
        vis[u] = true;

        int sz = graph[u].size();

        for (int j = 0; j < sz; j++)
        {
            int t = graph[u][j];
            if (!vis[t] && dis[t] > dis[u] + 1)
            {
                dis[t] = dis[u] + 1;
                paths[t].clear();
                paths[t].push_back(u);
            }
            else if (!vis[t] && dis[t] == dis[u] + 1)
                paths[t].push_back(u);
        }

        int min_dis = INT_MAX;
        int v = -1;


        for (int j = 0; j < cur_hash; j++)
        {
            if (!vis[j] && min_dis > dis[j])
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
            int d, h;
            scanf("%d", &d);

            h = get_hash(d);

            if (last != -1)
            {
                graph[last].push_back(h);
                graph[h].push_back(last);
                stop_com[last][h] = stop_com[h][last] = i + 1;
            }
            last = h;
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int s, t, sh, th;
        scanf("%d %d", &s, &t);
        sh = get_hash(s);
        th = get_hash(t);

        dijkstra(sh);

        if (dis[th] == INT_MAX)
            printf("Sorry, no line is available.\n");
        else
        {
            vector<int> tp;
            tp.push_back(th);

            best_path.clear();
            best_transfer = INT_MAX;

            dfs(th, sh, tp, 0, -1);
            printf("%d\n", best_path.size() - 1);

            int j = best_path.size() - 1;

            int sstop = best_path[j], dstop = best_path[j - 1];
            int last_com = stop_com[sstop][dstop];

            j -= 2;

            while (j >= 0)
            {
                if (last_com != stop_com[dstop][best_path[j]])
                {
                    printf("Go by the line of company #%d from %04d to %04d.\n", last_com, get_id(sstop), get_id(dstop));
                    sstop = dstop;
                    dstop = best_path[j];
                    last_com = stop_com[sstop][dstop];
                }
                else
                    dstop = best_path[j];
                j--;
            }

            printf("Go by the line of company #%d from %04d to %04d.\n", last_com, get_id(sstop), get_id(dstop));
        }
    }

    return 0;
}
