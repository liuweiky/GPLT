#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX_L 64
#define MAX_M 1300
#define MAX_N 150

using namespace std;

int M, N, L, T;
int cubic[MAX_L][MAX_M][MAX_N];
bool visit[MAX_L][MAX_M][MAX_N];
int vol = 0;

struct point
{
    int l, m, n;
    point(int _l, int _m, int _n): l(_l), m(_m), n(_n) {}
};

void bfs(int l, int m, int n)
{
    queue<point> q;
    q.push(point(l, m, n));
    int local_cnt = 1;
    visit[l][m][n] = true;
    while (!q.empty())
    {
        point p = q.front();
        q.pop();
        int i = p.l, j = p.m, k = p.n;
        if (!visit[i - 1][j][k] && cubic[i - 1][j][k])
        {
            local_cnt++;
            visit[i - 1][j][k] = true;
            q.push(point(i - 1, j, k));
        }
        if (!visit[i + 1][j][k] && cubic[i + 1][j][k])
        {
            local_cnt++;
            visit[i + 1][j][k] = true;
            q.push(point(i + 1, j, k));
        }
        if (!visit[i][j - 1][k] && cubic[i][j - 1][k])
        {
            local_cnt++;
            visit[i][j - 1][k] = true;
            q.push(point(i, j - 1, k));
        }
        if (!visit[i][j + 1][k] && cubic[i][j + 1][k])
        {
            local_cnt++;
            visit[i][j + 1][k] = true;
            q.push(point(i, j + 1, k));
        }
        if (!visit[i][j][k - 1] && cubic[i][j][k - 1])
        {
            local_cnt++;
            visit[i][j][k - 1] = true;
            q.push(point(i, j, k - 1));
        }
        if (!visit[i][j][k + 1] && cubic[i][j][k + 1])
        {
            local_cnt++;
            visit[i][j][k + 1] = true;
            q.push(point(i, j, k + 1));
        }
    }
    if (local_cnt >= T)
        vol += local_cnt;
}

int main()
{
    fill_n(&cubic[0][0][0], MAX_L * MAX_M * MAX_N, 0);
    fill_n(&visit[0][0][0], MAX_L * MAX_M * MAX_N, false);
    scanf("%d %d %d %d", &M, &N, &L, &T);

    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 1; k <= N; k++)
                scanf("%d", &cubic[i][j][k]);
    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 1; k <= N; k++)
                if (!visit[i][j][k] && cubic[i][j][k])
                    bfs(i, j, k);
    printf("%d", vol);
    return 0;
}
