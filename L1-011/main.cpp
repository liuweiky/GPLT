#include <cstdio>
#include <algorithm>

#define MAX_N 10240

using namespace std;

char str[MAX_N];
bool mp[256];

int main()
{
    fill_n(mp, 256, true);
    int len = 0;
    char ch;
    while((ch = getchar()) != '\n')
        str[len++] = ch;
    while((ch = getchar()) != '\n')
        mp[ch] = false;
    for (int i = 0; i < len; i++)
        if (mp[str[i]])
            printf("%c", str[i]);
    return 0;
}
