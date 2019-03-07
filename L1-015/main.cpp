#include <cstdio>
#include <cmath>

using namespace std;

int N;
char c;

int main()
{
    scanf("%d %c", &N, &c);

    int h = round(N / 2.0);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%c", c);
        if (i != h - 1)
            printf("\n");
    }

    return 0;
}
