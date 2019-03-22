#include <cstdio>

#define MAX_K 10240

using namespace std;

int matrix1[MAX_K][MAX_K], matrix2[MAX_K][MAX_K];

int m1, n1, m2, n2;

int main()
{
    scanf("%d %d", &m1, &n1);

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &matrix1[i][j]);

    scanf("%d %d", &m2, &n2);

    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &matrix2[i][j]);

    if (n1 != m2)
    {
        printf("Error: %d != %d", n1, m2);
        return 0;
    }

    printf("%d %d\n", m1, n2);

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            int sum = 0;
            for (int k = 0; k < n1; k++)
                sum += matrix1[i][k] * matrix2[k][j];
            if (j != 0)
                printf(" ");
            printf("%d", sum);
        }
        printf("\n");
    }

    return 0;
}
