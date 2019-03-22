#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAX_LEN 1024

using namespace std;

int N;
char str[MAX_LEN];
char matrix[MAX_LEN][MAX_LEN];
int len = 0;

int main()
{
    fill_n(&matrix[0][0], MAX_LEN * MAX_LEN, ' ');
    fill_n(str, MAX_LEN, ' ');

    scanf("%d", &N);

    char ch;
    getchar();
    while ((ch = getchar()) != '\n')
        str[len++] = ch;

    int i = 0, j = 0;

    for (int ptr = 0; ptr < len; ptr++)
    {
        if (j == N)
        {
            i++;
            j = 0;
        }
        matrix[i][j] = str[ptr];
        j++;
    }
    for (int u = 0; u < N; u++)
    {
        for (int t = i; t >= 0; t--)
            printf("%c", matrix[t][u]);
        printf("\n");
    }

    return 0;
}
