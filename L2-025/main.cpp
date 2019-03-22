#include <cstdio>
#include <vector>
#include <cstring>

#define MAX_N 10240

using namespace std;

vector<int> graph[MAX_N];
int degree[MAX_N] = {0};
int mirror_degree[MAX_N];

int N, M, K;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        /*if (s == t)
            continue;*/
        graph[s].push_back(t);
        graph[t].push_back(s);
        degree[s]++;
        degree[t]++;
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        memcpy(mirror_degree, degree, MAX_N * sizeof(int));
        int np, t;
        scanf("%d", &np);

        for (int j = 0; j < np; j++)
        {
            scanf("%d", &t);
            int sz = graph[t].size();
            for (int k = 0; k < sz; k++)
                mirror_degree[graph[t][k]]--;
            mirror_degree[t] = 0;
        }

        bool flag = true;

        for (int i = 1; i <= N; i++)
            if (mirror_degree[i] > 0)
            {
                flag = false;
                break;
            }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
