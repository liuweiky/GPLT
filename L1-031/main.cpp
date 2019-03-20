#include <cstdio>
#include <cmath>

using namespace std;

int N;

void judge(double h, double w)
{
    double standard = (h - 100) * 0.9 * 2;
    if (abs(w - standard) < standard * 0.1)
        printf("You are wan mei!\n");
    else if (w > standard)
        printf("You are tai pang le!\n");
    else
        printf("You are tai shou le!\n");
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        double h, w;
        scanf("%lf %lf", &h, &w);
        judge(h, w);
    }

    return 0;
}
