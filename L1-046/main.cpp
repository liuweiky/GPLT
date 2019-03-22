#include <cstdio>

using namespace std;

int x;

int main()
{
    scanf("%d", &x);

    unsigned long long t = 1, len = 1;

    while (t < x)
    {
        t *= 10;
        t++;
        len++;
    }

    while (true)
    {
        printf("%d", t / x);
        if (t % x == 0)
            break;
        t %= x;
        t *= 10;
        t++;
        len++;
    }

    printf(" %d", len);

    return 0;
}
