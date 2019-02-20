#include <cstdio>
#include <cstring>
#include <map>

#define MAX_LEN 10240

using namespace std;

map<char, char*> mp;
char N[MAX_LEN];

int main()
{
    mp['0'] = "ling";
    mp['1'] = "yi";
    mp['2'] = "er";
    mp['3'] = "san";
    mp['4'] = "si";
    mp['5'] = "wu";
    mp['6'] = "liu";
    mp['7'] = "qi";
    mp['8'] = "ba";
    mp['9'] = "jiu";
    scanf("%s", N);

    int len = strlen(N);

    int i = 0;
    bool neg = false;

    if (N[0] == '-')
    {
        neg = true;
        i++;
    }

    while (i < len && N[i] == '0')
        i++;

    if (i == len)
    {
        printf("ling");
        return 0;
    }

    if (neg)
        printf("fu ");

    for (; i < len; i++)
    {
        printf("%s", mp[N[i]]);
        if (i != len - 1)
            printf(" ");
    }

    return 0;
}
