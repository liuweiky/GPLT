#include <cstdio>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX_N 102400

using namespace std;

long long C[MAX_N];
long long arr[MAX_N];

int N, Q;

int low_bit(int x)
{
    return x & (-x);
}

void update(int idx, long long delta)
{
    arr[idx] += delta;
    for (int i = idx; i <= N - 1; i += low_bit(i))
        C[i] = min(C[i], arr[idx]);
}

long long get_min(int lp, int rp)
{
    // For more details, visit this blog:
    // https://blog.csdn.net/u010598215/article/details/48206959

    long long minn = LONG_LONG_MAX;
    minn = min(minn, arr[rp]);
    // Firstly, get the min of the segment where rp is in.
    for (; rp - low_bit(rp) >= lp; rp -= low_bit(rp))
        minn = min(minn, C[rp]);
    // For the remaining [lp, rp - 1] segment, compare one by one.
    while (lp <= rp)
    {
        minn = min(minn, arr[rp]);
        rp--;
    }
    return minn;
}

struct cmp
{
    bool operator() (pair<int, int> p1, pair<int, int> p2)
    {
        return get_min(p1.first, p1.second) < get_min(p2.first, p2.second);
    }
};


priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;

int main()
{
    fill_n(C, MAX_N, INT_MAX);
    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N - 1; i++)
    {
        long long t;
        scanf("%lld", &t);
        update(i, t);
    }

    for (int i = 0; i < Q; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        q.push(make_pair(min(s, t) + 1, max(s, t)));
    }

    /*for (int i = 1; i <= N - 1; i++)
        printf("%d ", C[i]);
    printf("\n");*/

    long long total = 0;

    while (q.size() > 0 && get_min(q.top().first, q.top().second) >= 0)
    {
        //printf("%d %d %d\n", q.top().first, q.top().second, get_min(q.top().first, q.top().second));
        long long delta = -get_min(q.top().first, q.top().second);
        total += -delta;
        for (int i = q.top().first; i <= q.top().second; i++)
            update(i, delta);
        q.pop();
    }

    printf("%lld", total);


    return 0;
}
