#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        int g, h, w;
        scanf("%d %d %d", &g, &h, &w);

        if (g == 1)
        {
            if (h > 130)
                printf("ni li hai! ");
            else if (h < 130)
                printf("duo chi yu! ");
            else
                printf("wan mei! ");

            if (w > 27)
                printf("shao chi rou!\n");
            else if (w < 27)
                printf("duo chi rou!\n");
            else
                printf("wan mei!\n");
        }
        else
        {
            if (h > 129)
                printf("ni li hai! ");
            else if (h < 129)
                printf("duo chi yu! ");
            else
                printf("wan mei! ");

            if (w > 25)
                printf("shao chi rou!\n");
            else if (w < 25)
                printf("duo chi rou!\n");
            else
                printf("wan mei!\n");
        }
    }

    return 0;
}
