#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_LEN 1024

using namespace std;

char N[MAX_LEN];
int digit[10];

int main()
{
    fill_n(digit, 10, 0);
    scanf("%s", N);
    int len = strlen(N);
    for (int i = 0; i < len; i++)
        digit[N[i] - '0']++;
    for (int i = 0; i <= 9; i++)
        if (digit[i] != 0)
            printf("%d:%d\n", i, digit[i]);
    return 0;
}
