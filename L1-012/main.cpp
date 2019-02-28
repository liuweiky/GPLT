#include <cstdio>

using namespace std;

int my_pow(int s, int k)
{
    if (k == 0)
        return 1;
    int sq = my_pow(s, k / 2);
    if (k % 2 == 1)
        return sq * sq * s;
    else
        return sq * sq;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("2^%d = %d", n, my_pow(2, n));
    return 0;
}
