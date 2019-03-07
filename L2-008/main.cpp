#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX_LEN 1024

using namespace std;

char str[MAX_LEN];
int len = 0;
int dp[MAX_LEN][MAX_LEN];

int main()
{
    fill_n(&dp[0][0], MAX_LEN * MAX_LEN, 0);
    char ch;
    while ((ch = getchar()) != '\n')
        str[len++] = ch;

    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i != len - 1 && str[i] == str[i + 1])
            dp[i][i + 1] = 2;
    }

    for (int l = 2; l < len; l++)
    {
        for (int i = 0; i < len - l; i++)
        {
            int s = i, t = i + l;
            if (dp[s + 1][t - 1] != 0 && str[s] == str[t])
                dp[s][t] = dp[s + 1][t - 1] + 2;
        }
    }

    int max_len = INT_MIN;

    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++)
            max_len = max(max_len, dp[i][j]);

    printf("%d", max_len);

    return 0;
}
