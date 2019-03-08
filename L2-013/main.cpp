#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 512

using namespace std;

int N, M, K;

bool graph[MAX_N][MAX_N];
int cnt = 0;
bool visit[MAX_N];

void dfs(int u)
{
    visit[u] = true;
    for (int i = 0; i < N; i++)
    {
        if (!visit[i] && graph[u][i])
            dfs(i);
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, false);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][t] = graph[t][s] = true;
    }

    fill_n(visit, MAX_N, false);

    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            dfs(i);
            cnt++;
        }
    }

    scanf("%d", &K);

    vector<int> lost;

    for (int i = 0; i < K; i++)
    {

        int c;
        scanf("%d", &c);
        lost.push_back(c);
        bool is_iso = true;
        for (int j = 0; j < N; j++)
        {
            if (graph[c][j])
                is_iso = false;
            graph[c][j] = graph[j][c] = false;
        }

        if (is_iso)
        {
            cnt--;
            printf("City %d is lost.\n", c);
            if (cnt == 0)
            {
                printf("Game Over.");
                return 0;
            }
            continue;
        }

        fill_n(visit, MAX_N, false);
        for (int j = 0; j < lost.size(); j++)
            visit[lost[j]] = true;
        int cur_cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (!visit[j])
            {
                dfs(j);
                cur_cnt++;
            }
        }
        if (cur_cnt != cnt)
            printf("Red Alert: City %d is lost!\n", c);
        else
            printf("City %d is lost.\n", c);
        cnt = cur_cnt;
        if (cnt == 0)
        {
            printf("Game Over.");
            return 0;
        }
    }

    return 0;
}
