#include <cstdio>

#define MAX_STRLEN 16

using namespace std;

int L, N, LEN;

int ptr = 0;
int str[MAX_STRLEN];

void deci_to_26(int n)
{
    do {
        str[ptr++] = n % 26;
        n /= 26;
    } while (n);
}
int main()
{
    scanf("%d %d", &L, &N);

    LEN = 1;

    for (int i = 0; i < L; i++)
        LEN *= 26;

    int num = LEN - N;

    deci_to_26(num);

    for (int i = 0; i < L - ptr; i++)
        putchar('a');

    for (int i = ptr - 1; i >= 0; i--)
        putchar(str[i] + 'a');

    return 0;
}
