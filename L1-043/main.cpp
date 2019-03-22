#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 16

using namespace std;

struct rec
{
    int id;
    char type;
    int h, m;
};

vector<rec> recs;
int N;

inline int get_time(rec& r)
{
    return r.h * 60 + r.m;
}

bool cmp(rec& r1, rec& r2)
{
    if (r1.id != r2.id)
        return r1.id < r2.id;
    return get_time(r1) < get_time(r2);
}

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        recs.clear();
        while (true)
        {
            rec r;
            scanf("%d %c %d:%d", &r.id, &r.type, &r.h, &r.m);
            if (r.id == 0)
                break;
            recs.push_back(r);
        }
        sort(recs.begin(), recs.end(), cmp);
        int borrow = 0, total_time = 0;
        for (int i = 0; i < recs.size(); i++)
        {
            if (recs[i].type == 'E')
                continue;
            if (i + 1 < recs.size())
            {
                rec r1 = recs[i];
                rec r2 = recs[i + 1];
                if (r2.type == 'E' && r1.id == r2.id)
                {
                    borrow++;
                    total_time += (get_time(r2) - get_time(r1));
                    i++;
                }
            }
        }
        if (borrow == 0)
            printf("0 0\n");
        else
            printf("%d %d\n", borrow, (int)round((double)total_time / borrow));
    }

    return 0;
}
