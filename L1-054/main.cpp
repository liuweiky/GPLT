#include <cstdio>

#define MAX_N 128

using namespace std;

bool orig[MAX_N][MAX_N] = {0};
bool trans[MAX_N][MAX_N] = {0};

int N;
char fil;

int main()
{
    fil = getchar();
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        getchar();
        for (int j = 0; j < N; j++)
        {
            orig[i][j] = getchar() == '@' ? 1 : 0;
            trans[N - 1 - i][N - 1 - j] = orig[i][j];
        }
    }

    bool flag = true;

    for (int i = 0; i < N && flag; i++)
        for (int j = 0; j < N && flag; j++)
            if (orig[i][j] != trans[i][j])
            {
                flag = false;
                break;
            }

    if (flag)
        printf("bu yong dao le\n");

    for (int i = 0; i < N; i++, putchar('\n'))
        for (int j = 0; j < N; j++)
            if (trans[i][j])
                putchar(fil);
            else
                putchar(' ');


    return 0;
}
