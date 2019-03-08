#include <cstdio>
#include <cctype>

#define LEN 32

using namespace std;

int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char validate[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

char id[LEN];
int N;

bool check()
{
    int w = 0;
    for (int i = 0; i < 17; i++)
    {
        if (!isdigit(id[i]))
            return false;
        w += weight[i] * (id[i] - '0');
    }
    w %= 11;
    char c = validate[w];
    return c == id[17];
}

int main()
{
    scanf("%d", &N);

    bool tag = true;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", id);
        if (!check())
        {
            tag = false;
            printf("%s\n", id);
        }
    }

    if (tag)
        printf("All passed");

    return 0;
}
