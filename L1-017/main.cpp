#include <cstdio>
#include <cstring>

#define MAX_N 128

using namespace std;

char num[MAX_N];

int main()
{
    scanf("%s", num);

    bool is_neg = num[0] == '-';

    int len = strlen(num);

    int i = is_neg ? 1 : 0;
    int cnt2 = 0;

    for (; i < len; i++)
    {
        if (num[i] == '2')
            cnt2++;
    }

    int actual_len = is_neg ? len - 1 : len;
    double r = (double) cnt2 / actual_len;

    if (is_neg)
        r *= 1.5;
    if ((num[len - 1] - '0') % 2 == 0)
        r *= 2;

    printf("%.2f%%", r * 100);

    return 0;
}
