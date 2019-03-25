#include <cstdio>
#include <algorithm>

#define MAX_N 128
#define MAX_T 16

#define TEAM_MEMBER 10

using namespace std;

int uni_seat[MAX_N][MAX_T * TEAM_MEMBER];
int uni_tm_ptr[MAX_N];
int uni_teams[MAX_N];

int N;
int not_arrange;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &uni_teams[i]);

    fill_n(uni_tm_ptr, MAX_N, 0);

    not_arrange = N;
    int sptr = 1, uptr = 0;

    bool only_one = false;

    while (true)
    {
        uni_seat[uptr][uni_tm_ptr[uptr]] = sptr;
        uni_tm_ptr[uptr]++;
        if (uni_tm_ptr[uptr] == uni_teams[uptr] * TEAM_MEMBER)
            not_arrange--;
        if (not_arrange == 0)
            break;
        if (not_arrange == 1)
        {
            if (only_one || N == 1)
                sptr += 2;
            else
                sptr++;
            only_one = true;
        }
        else
            sptr++;
        uptr++;
        uptr %= N;
        while (uni_tm_ptr[uptr] == uni_teams[uptr] * TEAM_MEMBER)
        {
            uptr++;
            uptr %= N;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("#%d", i + 1);

        for (int j = 0; j < uni_teams[i] * TEAM_MEMBER; j++)
        {
            if (j % TEAM_MEMBER == 0)
                printf("\n");
            printf("%d", uni_seat[i][j]);
            if (j % TEAM_MEMBER != TEAM_MEMBER - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
