#include <cstdio>
#include <vector>
#include <climits>
#include <utility>
#include <queue>

#define MAX_N 10240

using namespace std;

int N, M, K;

vector<int> graph[MAX_N];

pair<int, int> best;
bool visit[MAX_N];

void bfs(int s)
{
    fill_n(visit, MAX_N, false);
    best.first = -1;
    best.second = INT_MIN;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(s, 0));
    visit[s] = true;
    while (!q.empty())
    {
        pair<int, int> ss = q.front();
        q.pop();
        if (ss.second > best.second || (ss.second == best.second && ss.first < best.first))
            best = ss;
        for (int i = 0; i < graph[ss.first].size(); i++)
        {
            if (!visit[graph[ss.first][i]])
            {
                visit[graph[ss.first][i]] = true;
                q.push(pair<int, int>(graph[ss.first][i], ss.second + 1));
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s].push_back(t);
        graph[t].push_back(s);
    }

    for (int i = 0; i < K; i++)
    {
        int s;
        scanf("%d", &s);
        bfs(s);
        if (best.first == s)
            printf("0\n");
        else
            printf("%d\n", best.first);
    }

    return 0;
}
