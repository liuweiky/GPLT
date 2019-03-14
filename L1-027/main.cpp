#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char digits[16];

int digit_cnt[10];
int rnk[10];

int main()
{
    fill_n(digit_cnt, 10, 0);

    scanf("%s", digits);

    for (int i = 0; i < 11; i++)
        digit_cnt[digits[i] - '0']++;

    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        if (digit_cnt[i] > 0)
            v.push_back(i);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    printf("int[] arr = new int[]{");

    for (int i = 0; i < v.size(); i++)
    {
        rnk[v[i]] = i;
        if (i != 0)
            printf(",");
        printf("%d", v[i]);
    }

    printf("};\nint[] index = new int[]{");

    for (int i = 0; i < 11; i++)
    {
        if (i != 0)
            printf(",");
        printf("%d", rnk[digits[i] - '0']);
    }

    printf("};");
    return 0;
}
