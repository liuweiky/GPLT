#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct mooncake
{
    double stock, price;
};

vector<mooncake> mks;
int N, D;

bool cmp(mooncake mk1, mooncake mk2)
{
    return mk1.price / mk1.stock > mk2.price / mk2.stock;
}

int main()
{
    scanf("%d %d", &N, &D);

    for (int i = 0; i < N; i++)
    {
        double s;
        scanf("%lf", &s);
        mooncake mk;
        mk.stock = s;
        mks.push_back(mk);
    }

    for (int i = 0; i < N; i++)
    {
        double p;
        scanf("%lf", &p);
        mks[i].price = p;
    }

    sort(mks.begin(), mks.end(), cmp);

    double gain = 0;
    int p = 0;

    while (D > 0 && p < N)
    {
        if (D > mks[p].stock)
        {
            D -= mks[p].stock;
            gain += mks[p].price;
            p++;
        }
        else
        {
            gain += D * mks[p].price / mks[p].stock;
            D = 0;
        }
    }

    printf("%.2f", gain);

    return 0;
}
