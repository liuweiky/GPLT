#include <cstdio>
#include <cctype>

#define MAX_LEN 1024

using namespace std;

char sbuf[MAX_LEN];
int len = 0;
char sa[MAX_LEN], sb[MAX_LEN];

int main()
{
    char c;
    while ((c = getchar()) != '\n')
        sbuf[len++] = c;

    int k;

    for (k = 0; k < len; k++)
    {
        if (sbuf[k] == ' ')
            break;
        sa[k] = sbuf[k];
    }

    sa[k] = '\0';

    int la = k, lb = 0, a, b;
    bool aunknown = false, bunknown = false;

    k++;

    for (; k < len; k++)
        sb[lb++] = sbuf[k];

    sb[lb] = '\0';
    for (int i = 0; i < la; i++)
        if (!isdigit(sa[i]))
        {
            aunknown = true;
            break;
        }

    if (!aunknown)
        sscanf(sa, "%d", &a);

    if (a == 0 || aunknown || la == 0 || a > 1000)
    {
        aunknown = true;
        printf("?");
    }
    else
        printf("%d", a);

    printf(" + ");

    for (int i = 0; i < lb; i++)
        if (!isdigit(sb[i]))
    {
        bunknown = true;
        break;
    }

    if (!bunknown)
        sscanf(sb, "%d", &b);

    if (b == 0|| bunknown || lb == 0|| b > 1000)
    {
        bunknown = true;
        printf("?");
    }
    else
        printf("%d", b);

    printf(" = ");

    if (aunknown || bunknown)
        printf("?");
    else
        printf("%d", a + b);

    return 0;
}
