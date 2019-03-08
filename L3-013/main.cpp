#include <cstdio>

#define g 9.8

using namespace std;

double m, E;
double dp;

int main()
{
    int w, p;
    E = 1000.0;
    scanf("%d %d", &w, &p);
    m = w / 100.0;
    dp = (100 - p) / 100.0;

    double x = (2 * E) / (m * g);

    while (E > 1e-10)
    {
        E *= dp;
        x += (2 * E) / (m * g);
    }

    printf("%.3f", x);

    return 0;
}
