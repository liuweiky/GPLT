#include <cstdio>
#include <utility>
#include <string>
#include <algorithm>

#define MAX_N 64

using namespace std;

int N;

pair<int, string> stus[MAX_N];
bool vis[MAX_N];

int main()
{
    fill_n(vis, MAX_N, false);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        char buf[16];
        scanf("%d %s", &stus[i].first, buf);
        stus[i].second = buf;
    }

    int lptr = 1, rptr = N;

    for (int i = 1; i <= N / 2; i++)
    {
        rptr = N;
        while (vis[lptr]) lptr++;
        pair<int, string> a = stus[lptr];
        vis[lptr] = true;
        while (vis[rptr] || stus[rptr].first == a.first) rptr--;
        pair<int, string> b = stus[rptr];
        vis[rptr] = true;
        printf("%s %s\n", a.second.c_str(), b.second.c_str());
    }

    return 0;
}
