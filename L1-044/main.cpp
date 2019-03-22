#include <cstdio>

using namespace std;

int K;

int main()
{
    int cnt = 0;
    scanf("%d", &K);
    while (true)
    {
        char buf[16];
        scanf("%s", buf);
        if (buf[0] == 'E')
            break;
        if (cnt == K)
        {
            printf("%s\n", buf);
            cnt = 0;
            continue;
        }
        if (buf[0] == 'C')
            printf("Bu\n");
        else if (buf[0] == 'J')
            printf("ChuiZi\n");
        else
            printf("JianDao\n");
        cnt++;
    }
    return 0;
}
