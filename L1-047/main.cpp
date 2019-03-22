#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        char buf[16];
        int a, b;
        scanf("%s %d %d", buf, &a, &b);
        if (a < 15 || a > 20 || b < 50 || b > 70)
            printf("%s\n", buf);
    }

    return 0;
}
