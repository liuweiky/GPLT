#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 10240

using namespace std;

struct Point
{
    long long x, y;
    Point operator- (const Point& rhs) const
    {
        Point p;
        p.x = x - rhs.x;
        p.y = y - rhs.y;
        return p;
    }
};

int N;
vector<Point> ptsup;
vector<Point> ptsdown;

int cvx_hull_up[MAX_N];
int cvx_hull_down[MAX_N];

int upptr = 0;
int downptr = 0;

bool cmp(Point& p1, Point& p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

long long det(Point& p1, Point& p2, Point& p3, Point& p4)
{
    Point vec1 = p2 - p1;
    Point vec2 = p4 - p3;
    return vec1.x * vec2.y - vec2.x * vec1.y;
}

bool upper_pt(Point& p1, Point& p2, Point& pt)
{
    return ((double)(p1.y - p2.y) / (p1.x - p2.x)) * (pt.x - p1.x) + p1.y >= (double)pt.y;

    // since x, y are long long, the codes below is not correct.
    //return ((p1.y - p2.y) / (p1.x - p2.x)) * (pt.x - p1.x) + p1.y >= pt.y;

    // Wrong inequality operation !
    //return (p1.y - p2.y) * (pt.x - p1.x) + p1.y * (p1.x - p2.x) >= pt.y * (p1.x - p2.x);
}

bool lower_pt(Point& p1, Point& p2, Point& pt)
{
    return ((double)(p1.y - p2.y) / (p1.x - p2.x)) * (pt.x - p1.x) + p1.y <= (double)pt.y;
    //return ((p1.y - p2.y) / (p1.x - p2.x)) * (pt.x - p1.x) + p1.y <= pt.y;
    //return (p1.y - p2.y) * (pt.x - p1.x) + p1.y * (p1.x - p2.x) <= pt.y * (p1.x - p2.x);
}

void cvx_up()
{
    for (int i = 0; i < N; i++)
    {
        while (upptr >= 2 && det(ptsup[cvx_hull_up[upptr - 2]], ptsup[cvx_hull_up[upptr - 1]], ptsup[cvx_hull_up[upptr - 1]], ptsup[i]) <= 0)
            upptr--;
        cvx_hull_up[upptr++] = i;
    }
}

void cvx_down()
{
    for (int i = 0; i < N; i++)
    {
        while (downptr >= 2 && det(ptsdown[cvx_hull_down[downptr - 2]], ptsdown[cvx_hull_down[downptr - 1]], ptsdown[cvx_hull_down[downptr - 1]], ptsdown[i]) >= 0)
            downptr--;
        cvx_hull_down[downptr++] = i;
    }
}

void find_seg()
{
    for (int i = 0; i < upptr - 1; i++)
    {
        int j;
        for (j = 0; j < ptsdown.size(); j++)
        {
            if (!upper_pt(ptsup[cvx_hull_up[i]], ptsup[cvx_hull_up[i + 1]], ptsdown[j]))
                break;
        }
        if (j == ptsdown.size())
        {
            printf("%lld %lld %lld %lld", ptsup[cvx_hull_up[i]].x, ptsup[cvx_hull_up[i]].y, ptsup[cvx_hull_up[i + 1]].x, ptsup[cvx_hull_up[i + 1]].y);
            return;
        }
    }

    for (int i = 0; i < downptr - 1; i++)
    {
        int j;
        for (j = 0; j < ptsup.size(); j++)
        {
            if (!lower_pt(ptsdown[cvx_hull_down[i]], ptsdown[cvx_hull_down[i + 1]], ptsup[j]))
                break;
        }
        if (j == ptsup.size())
        {
            printf("%lld %lld %lld %lld", ptsdown[cvx_hull_down[i]].x, ptsdown[cvx_hull_down[i]].y, ptsdown[cvx_hull_down[i + 1]].x, ptsdown[cvx_hull_down[i + 1]].y);
            return;
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        long long x, y1, y2;
        Point up, down;

        scanf("%lld %lld %lld", &x, &y1, &y2);
        up.x = x; up.y = y1;
        down.x = x; down.y = y2;
        ptsup.push_back(up);
        ptsdown.push_back(down);
    }

    if (N == 1)
    {
        printf("-1 %lld 1 %lld", (ptsup[0].y + ptsdown[0].y) / 2, (ptsup[0].y + ptsdown[0].y) / 2);
        return 0;
    }

    sort(ptsup.begin(), ptsup.end(), cmp);
    sort(ptsdown.begin(), ptsdown.end(), cmp);

    cvx_up();
    cvx_down();

    /*printf("\n");

    for (int i = 0; i < upptr; i++)
        printf("%lld %.lld\n", ptsup[cvx_hull_up[i]].x, ptsup[cvx_hull_up[i]].y);

    printf("\n");

    for (int i = 0; i < downptr; i++)
        printf("%lld %lld\n", ptsdown[cvx_hull_down[i]].x, ptsdown[cvx_hull_down[i]].y);*/

    find_seg();

    return 0;
}
