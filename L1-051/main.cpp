#include <cstdio>

using namespace std;

double N, discount;

int main()
{
    scanf("%lf %lf", &N, &discount);
    printf("%.2f", N / 10 * discount);
    return 0;
}
