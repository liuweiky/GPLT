#include <cstdio>

using namespace std;

int main()
{
    int d;
    scanf("%d", &d);
    printf("%d", (d - 1 + 2) % 7 + 1);
    return 0;
}
