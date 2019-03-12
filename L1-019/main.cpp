#include <cstdio>

using namespace std;

int ma, mb;
int N;

int main()
{
    scanf("%d %d %d", &ma, &mb, &N);

    int ta = 0, tb = 0;

    for (int i = 0; i < N; i++)
    {
        int as, ah, bs, bh;
        scanf("%d %d %d %d", &as, &ah, &bs, &bh);
        if ((ah == as + bs && bh == as + bs) || (ah != as + bs && bh != as + bs))
            continue;
        if (ah == as + bs)
            ta++;
        else if (bh == as + bs)
            tb++;
        if (ta == ma + 1)
        {
            printf("A\n%d", tb);
            return 0;
        }
        if (tb == mb + 1)
        {
            printf("B\n%d", ta);
            return 0;
        }

    }

    return 0;
}
