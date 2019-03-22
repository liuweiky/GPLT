#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    getchar();

    for (int i = 0; i < N; i++)
    {
        char c;
        double h;
        scanf("%c %lf", &c, &h);
        if (c == 'M')
            printf("%.2f\n", h / 1.09);
        else
            printf("%.2f\n", h * 1.09);
        getchar();
    }

    return 0;
}
