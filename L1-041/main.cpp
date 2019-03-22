#include <cstdio>

using namespace std;

int main()
{
    int cnt = 0, n;

    while (scanf("%d", &n) != EOF)
    {
        cnt++;
        if (n == 250)
        {
            printf("%d", cnt);
            return 0;
        }
    }

    return 0;
}
