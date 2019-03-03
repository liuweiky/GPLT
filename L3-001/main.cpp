#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define MAX_N 10240
#define MAX_M 128

using namespace std;

int N, M;

int dp[MAX_M];
int w[MAX_N];
int c[MAX_N];

bool choice[MAX_N][MAX_M];

int main()
{
    fill_n(&choice[0][0], MAX_N * MAX_M, false);
    fill_n(dp, MAX_M, 0);
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &w[i]);
    }

    sort(w + 1, w + N + 1);
    reverse(w + 1, w + N + 1);
    memcpy(c, w, MAX_N * sizeof(int));

    for (int i = 1; i <= N; i++)
    {
        for (int m = M; m >= w[i]; m--)
        {
            if (dp[m] <= dp[m - w[i]] + c[i])
            {
                dp[m] = dp[m - w[i]] + c[i];
                choice[i][m] = true;
            }
        }
    }

    if (dp[M] != M)
    {
        printf("No Solution");
        return 0;
    }

    int mt = M, it = N;

    vector<int> ans;

    while (mt > 0)
    {
        if (choice[it][mt])
        {
            ans.push_back(c[it]);
            mt -= w[it];
        }
        it--;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
