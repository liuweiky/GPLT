#include <cstdio>
#include <cmath>

using namespace std;

int N;
char symb;

int main()
{
    scanf("%d %c", &N, &symb);
    int t = sqrt((N + 1) / 2);
    int rem = N - (2 * t * t - 1);

    for (int i = t; i >= 1; i--)
    {
        for (int j = 1; j <= t - i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", symb);
        /*for (int j = 1; j <= t - i; j++)
            printf(" ");*/
        printf("\n");
    }
    for (int i = 2; i <= t; i++)
    {
        for (int j = 1; j <= t - i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", symb);
        /*for (int j = 1; j <= t - i; j++)
            printf(" ");*/
        printf("\n");
    }
    printf("%d", rem);
    return 0;
}
