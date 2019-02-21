#include <cstdio>

using namespace std;

int A, B;

int main()
{
    scanf("%d %d", &A, &B);

    int cnt = 0;
    for (int i = A; i <= B; i++)
    {
        printf("%5d", i);
        cnt++;
        if (cnt % 5 == 0)
            printf("\n");
    }

    if (cnt % 5 != 0)
        printf("\n");

    printf("Sum = %d", (A + B) * (B - A + 1) / 2);

    return 0;
}
