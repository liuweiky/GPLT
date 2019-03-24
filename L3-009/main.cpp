#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 102400

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

vector<Point> pts;
int ans[MAX_N];
bool flag[MAX_N];
int ptr = 0;
int N;

long long det(Point& p1, Point& p2, Point& p3, Point& p4)
{
    Point vec1 = p2 - p1;
    Point vec2 = p4 - p3;
    return vec1.x * vec2.y - vec2.x * vec1.y;
}

void Graham()
{
    for (int i = 0; i < N; i++)
    {
        while (ptr >= 2 && det(pts[ans[ptr - 2]], pts[ans[ptr - 1]], pts[ans[ptr - 1]], pts[i]) <= 0)
            ptr--;
        flag[ans[ptr - 1]] = true;
        //printf("%lld, %lld\n", pts[ans[ptr - 1]].x, pts[ans[ptr - 1]].y);
        ans[ptr++] = i;
    }
}

int main()
{
    fill_n(flag, MAX_N, false);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        Point p;
        scanf("%lld %lld", &p.x, &p.y);
        pts.push_back(p);
    }

    int cnt = 0;

    Graham();

    for (int i = 1; i < N; i++)
        if (flag[i])
            cnt++;

    printf("%d", cnt);

    return 0;
}
