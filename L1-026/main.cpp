#include <cstdio>
#include <cstring>

using namespace std;

char str[] = "I Love GPLT";

int main()
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (i != 0)
            printf("\n");
        printf("%c", str[i]);
    }

    return 0;
}
