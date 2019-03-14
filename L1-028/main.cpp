#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int p)
{
    if (p < 2)
        return false;

    int sqrtp = sqrt(p);

    for (int i = 2; i <= sqrtp; i++)
        if (p % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if (i != 0)
            printf("\n");
        if (is_prime(t))
            printf("Yes");
        else
            printf("No");
    }

    return 0;
}
