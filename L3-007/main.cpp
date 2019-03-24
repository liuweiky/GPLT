#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 512

using namespace std;

int N, M;
int P, Q;
int graphl[MAX_N][MAX_N];
int grapht[MAX_N][MAX_N];

vector<int> pathl[MAX_N];
vector<int> patht[MAX_N];

int dis[MAX_N];
bool visit[MAX_N];

vector<int> ansl;
vector<int> anst;

int best_len;

bool same = true;
int total_t = 0;
int total_len = 0;

void dijkstra_l(int u)
{
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(visit, MAX_N, false);
    dis[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        visit[u] = true;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && graphl[u][j] > 0 && dis[j] > dis[u] + graphl[u][j])
            {
                dis[j] = dis[u] + graphl[u][j];
                pathl[j].clear();
                pathl[j].push_back(u);
            }
            else if (!visit[j] && graphl[u][j] > 0 && dis[j] == dis[u] + graphl[u][j])
                pathl[j].push_back(u);
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

void dfsl(int u, vector<int> p)
{
    if (u == P)
    {
        if (ansl.size() == 0 || p.size() < ansl.size())
            ansl = p;
        return;
    }
    for (int i = 0; i < pathl[u].size(); i++)
    {
        int v = pathl[u][i];
        p.push_back(v);
        dfsl(v, p);
        p.pop_back();
    }
}

void dijkstra_t(int u)
{
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(visit, MAX_N, false);
    dis[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        visit[u] = true;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && grapht[u][j] > 0 && dis[j] > dis[u] + grapht[u][j])
            {
                dis[j] = dis[u] + grapht[u][j];
                patht[j].clear();
                patht[j].push_back(u);
            }
            else if (!visit[j] && grapht[u][j] > 0 && dis[j] == dis[u] + grapht[u][j])
                patht[j].push_back(u);
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

void dfst(int u, vector<int> p)
{
    if (u == P)
    {
        int len = 0;
        for (int i = p.size() - 1; i > 0; i--)
            len += graphl[p[i]][p[i - 1]];
        if (anst.size() == 0 || len < best_len)
        {
            best_len = len;
            anst = p;
            return;
        }
    }
    for (int i = 0; i < patht[u].size(); i++)
    {
        int v = patht[u][i];
        p.push_back(v);
        dfst(v, p);
        p.pop_back();
    }
}

void check_path()
{
    if (ansl.size() != anst.size())
    {
        same = false;
        return;
    }
    for (int i = 0; i < ansl.size(); i++)
    {
        if (ansl[i] != anst[i])
        {
            same = false;
            return;
        }
    }
}

int main()
{
    fill_n(&graphl[0][0], MAX_N * MAX_N, -1);
    fill_n(&grapht[0][0], MAX_N * MAX_N, -1);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int v1, v2, oneway, l, t;
        scanf("%d %d %d %d %d", &v1, &v2, &oneway, &l, &t);
        graphl[v1][v2] = l;
        grapht[v1][v2] = t;
        if (oneway == 0)
        {
            graphl[v2][v1] = graphl[v1][v2];
            grapht[v2][v1] = grapht[v1][v2];
        }
    }

    scanf("%d %d", &P, &Q);

    vector<int> tmp;
    tmp.push_back(Q);

    dijkstra_l(P);
    total_len = dis[Q];
    dfsl(Q, tmp);


    dijkstra_t(P);
    total_t = dis[Q];
    dfst(Q, tmp);

    check_path();

    if (same)
    {
        printf("Time = %d; Distance = %d: ", total_t, total_len);
        for (int i = anst.size() - 1; i >= 0; i--)
        {
            printf("%d", anst[i]);
            if (i != 0)
                printf(" => ");
        }
        return 0;
    }
    printf("Time = %d: ", total_t);
    for (int i = anst.size() - 1; i >= 0; i--)
    {
        printf("%d", anst[i]);
        if (i != 0)
            printf(" => ");
    }
    printf("\n");
    printf("Distance = %d: ", total_len);
    for (int i = ansl.size() - 1; i >= 0; i--)
    {
        printf("%d", ansl[i]);
        if (i != 0)
            printf(" => ");
    }

    return 0;
}
