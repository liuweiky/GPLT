#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>

#define MAX_N 10240

using namespace std;

int depend[MAX_N];
bool is_dep[MAX_N];
int A, B;

int trans(int t)
{
    int res = 0;
    do
    {
        int k = t % 10;
        res += k * k;
        t /= 10;
    } while (t);

    return res;
}

bool is_prime(int p)
{
    if (p < 2)
        return false;
    int sp = sqrt(p);
    for (int i = 2; i <= sp; i++)
        if (p % i == 0)
            return false;
    return true;
}

int main()
{
    fill_n(depend, MAX_N, -1);
    fill_n(is_dep, MAX_N, true);
    scanf("%d %d", &A, &B);

    for (int i = A; i <= B; i++)
    {
        if (!is_dep[i])
            continue;
        int cnt = 0;
        map<int, int> mp;
        bool flag = true;
        int k = i;
        while (k != 1 && flag)
        {
            mp[k] = cnt;
            k = trans(k);
            is_dep[k] = false;
            cnt++;
            if (mp.find(k) != mp.end())
                flag = false;
        }

        if (flag)
            depend[i] = cnt;
    }

    bool has = false;

    for (int i = A; i <= B; i++)
    {
        if (is_dep[i] && depend[i] != -1)
        {
            printf("%d %d\n", i, is_prime(i) ? depend[i] * 2 : depend[i]);
            has = true;
        }
    }

    if (!has)
        printf("SAD");

    return 0;
}
