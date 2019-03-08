#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX_N 102400

using namespace std;

int rail_min_num[MAX_N];
int cnt = 0;
int N;

void binary_insert(int t)
{
    int low = 1, high = cnt, up = cnt;
    if (cnt == 0)
    {
        cnt++;
        rail_min_num[cnt] = t;
        return;
    }
    if (rail_min_num[cnt] < t)
    {
        rail_min_num[++cnt] = t;
        return;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (rail_min_num[mid] < t)
            low = mid + 1;
        else
        {
            high = mid - 1;
            up = mid;
        }
    }
    rail_min_num[up] = t;
}

int main()
{
    scanf("%d", &N);

    rail_min_num[0] = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        binary_insert(t);
    }

    printf("%d", cnt);

    return 0;
}
