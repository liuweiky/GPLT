#include <cstdio>
#include <algorithm>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    int sum = 0, f = 1;

    for (int i = 1; i <= N; i++)
        sum += (f *= i);

    printf("%d", sum);
    return 0;
}
