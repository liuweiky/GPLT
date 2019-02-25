#include <cstdio>
#include <cmath>

using namespace std;

int N;

struct frac
{
    long long up, down;
};

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

frac reduction(frac f)
{
    if (f.down < 0)
    {
        f.up = -f.up;
        f.down = - f.down;
    }
    if (f.up == 0)
    {
        f.down = 1;
        return f;
    }
    if (f.down == 0)
    {
        f.up = 1;
        return f;
    }
    long long g = gcd(abs(f.up), f.down);
    f.up /= g;
    f.down /= g;
    return f;
}

void print_frac(frac f)
{
    f = reduction(f);
    if (f.down == 0)
    {
        printf("Inf");
        return;
    }
    if (f.up == 0)
    {
        printf("0");
        return;
    }
    if (f.down == 1)
    {
        printf("%lld", f.up);
        return;
    }
    if (f.up / f.down != 0)
    {
        printf("%lld ", f.up / f.down);
        if (f.up < 0)
            f.up = -f.up;
        printf("%lld/%lld", f.up % f.down, f.down);
    }
    else
        printf("%lld/%lld", f.up % f.down, f.down);


}

frac add(frac f1, frac f2)
{
    frac f;
    f.up = f1.up * f2.down + f2.up * f1.down;
    f.down = f1.down * f2.down;
    return f;
}

int main()
{
    frac sum;
    sum.up = 0;
    sum.down = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        frac f;
        scanf("%lld/%lld", &f.up, &f.down);
        sum = add(sum, f);
    }
    print_frac(sum);
    return 0;
}
