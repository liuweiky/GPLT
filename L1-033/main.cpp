#include <cstdio>
#include <algorithm>

using namespace std;

int y, n;
bool char_mp[10];

bool check(int yy)
{
    fill_n(char_mp, 10, false);
    char buf[10];
    sprintf(buf, "%04d", yy);
    int diff = 0;
    for (int i = 0; i < 4; i++)
        if (!char_mp[buf[i] - '0'])
        {
            diff++;
            char_mp[buf[i] - '0'] = true;
        }
    if (diff == n)
        return true;
    return false;
}

int main()
{
    scanf("%d %d", &y, &n);

    int yy = y;

    while (!check(yy)) yy++;

    printf("%d %04d", yy - y, yy);

    return 0;
}
