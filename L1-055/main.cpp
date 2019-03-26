#include <cstdio>

using namespace std;

int pa, pb;
int wa = 0, wb = 0;

int main()
{
    scanf("%d %d", &pa, &pb);

    getchar();
    getchar() == '0' ? wa++ : wb++;
    getchar();
    getchar() == '0' ? wa++ : wb++;
    getchar();
    getchar() == '0' ? wa++ : wb++;


    if ((pa > pb && wa >= 1) || (pa < pb && wa == 3))
        printf("The winner is a: %d + %d", pa, wa);
    else
        printf("The winner is b: %d + %d", pb, wb);

    return 0;
}
