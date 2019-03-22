#include <cstdio>

using namespace std;

int y, m, d;

int main()
{
    scanf("%d-%d-%d", &m, &d, &y);
    printf("%04d-%02d-%02d", y, m, d);
    return 0;
}
