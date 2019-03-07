#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_N 256

using namespace std;


int graph[MAX_N][MAX_N];
int city_enm[MAX_N];

map<string, int> str2hash;
map<int, string> hash2str;
int cur_hash = 0;
int N, K, S_hash, T_hash;

vector<int> path[MAX_N];

bool visit[MAX_N];
int dis[MAX_N];

int max_lib = INT_MIN;
int max_enm = INT_MAX;
vector<int> best_path;

int path_cnt = 0;

int get_hash(string s)
{
    if (str2hash.find(s) == str2hash.end())
    {
        str2hash[s] = cur_hash;
        hash2str[cur_hash++] = s;
    }
    return str2hash[s];
}

string get_str(int h)
{
    return hash2str[h];
}

void dijkstra(int u)
{
    fill_n(visit, MAX_N, false);
    fill_n(dis, MAX_N, INT_MAX);
    dis[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        visit[u] = true;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
            {
                dis[j] = dis[u] + graph[u][j];
                path[j].clear();
                path[j].push_back(u);
            }
            else if (!visit[j] && graph[u][j] > 0 && dis[j] == dis[u] + graph[u][j])
                path[j].push_back(u);
        }

        int min_dis = INT_MAX;
        int v = -1;

        for (int j = 0; j < N; j++)
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

void dfs(int c, vector<int> p)
{
    if (path[c].size() == 0)
    {
        path_cnt++;
        int lib = 0, enm = 0;
        for (int i = 0; i < p.size(); i++)
        {
            lib++;
            enm += city_enm[p[i]];
        }
        if (lib > max_lib)
        {
            best_path = p;
            max_lib = lib;
            max_enm = enm;
        } else if (lib == max_lib && enm > max_enm)
        {
            best_path = p;
            max_lib = lib;
            max_enm = enm;
        }
        return;
    }

    for (int i = 0; i < path[c].size(); i++)
    {
        int t = path[c][i];
        p.push_back(t);
        dfs(t, p);
        p.pop_back();
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, -1);
    fill_n(city_enm, MAX_N, 0);

    char sbuf[16];
    char tbuf[16];
    scanf("%d %d %s %s", &N, &K, sbuf, tbuf);
    S_hash = get_hash(sbuf);
    T_hash = get_hash(tbuf);

    for (int i = 0; i < N - 1; i++)
    {
        int e;
        scanf("%s %d", sbuf, &e);
        int h = get_hash(sbuf);
        city_enm[h] = e;
    }

    for (int i = 0; i < K; i++)
    {
        int s, t, d;
        scanf("%s %s %d", sbuf, tbuf, &d);
        s = get_hash(sbuf);
        t = get_hash(tbuf);
        graph[s][t] = graph[t][s] = d;
    }

    dijkstra(S_hash);

    vector<int> tmp;
    tmp.push_back(T_hash);
    dfs(T_hash, tmp);

    for (int i = best_path.size() - 1; i >= 0; i--)
    {
        printf("%s", get_str(best_path[i]).c_str());
        if (i != 0)
            printf("->");
        else
            printf("\n");
    }

    printf("%d %d %d", path_cnt, dis[T_hash], max_enm);

    return 0;
}
