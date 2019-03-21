#include <cstdio>

using namespace std;

int A, B;

int main()
{
    scanf("%d %d", &A, &B);
    printf("%d/", A);
    if (B < 0)
        printf("(%d)=", B);
    else
        printf("%d=", B);
    if (B == 0)
        printf("Error");
    else
        printf("%.2f", (double) A / B);
    return 0;
}
