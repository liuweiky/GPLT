#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 32

using namespace std;

int N;
int team_wins[MAX_N][MAX_N];
bool found = false;
bool vis[MAX_N];

vector<int> path;

void dfs(int t, vector<int>& p)
{
    if (p.size() == N)
    {
        if (!team_wins[p[p.size() - 1]][p[0]])
            return;
        found = true;
        path = p;
        return;
    }

    int i = 2;
    for (; i <= N; i++)
    {
        if (!vis[i] && team_wins[i][p[0]])
            break;
    }

    if (i > N)
        return;

    for (int i = 1; i <= N; i++)
        if (!found && team_wins[t][i] && !vis[i])
        {
            p.push_back(i);
            vis[i] = true;
            dfs(i, p);
            vis[i] = false;
            p.pop_back();
        }
}

int main()
{
    fill_n(&team_wins[0][0], MAX_N * MAX_N, false);
    fill_n(vis, MAX_N, false);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        getchar();
        for (int j = 1; j <= N; j++)
        {
            char c;
            c = getchar();
            if (c == 'W')
                team_wins[i][j] = true;
            else if (c == 'L')
                team_wins[j][i] = true;
        }
    }

    for (int i = 1; i <= N && !found; i++)
    {
        vector<int> p;
        p.push_back(i);
        vis[i] = true;
        dfs(i, p);
        vis[i] = false;
    }

    if (found)
    {
        for (int i = 0; i < path.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", path[i]);
        }
    }
    else
        printf("No Solution");

    return 0;
}
