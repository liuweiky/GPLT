#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_N 10240

using namespace std;

struct stu
{
    char account[64];
    int score;
};

int N, G, K;
vector<stu> stus;
int rnk[MAX_N];

bool cmp(stu& s1, stu& s2)
{
    if (s1.score != s2.score)
        return s1.score > s2.score;
    else
        return strcmp(s1.account, s2.account) < 0;
}

int main()
{
    scanf("%d %d %d", &N, &G, &K);

    int pat = 0;

    for (int i = 0; i < N; i++)
    {
        stu s;
        scanf("%s %d", s.account, &s.score);
        if (s.score >= G && s.score <= 100)
            pat += 50;
        else if (s.score < G && s.score >= 60)
            pat += 20;
        stus.push_back(s);
    }

    printf("%d\n", pat);

    sort(stus.begin(), stus.end(), cmp);

    rnk[0] = 1;

    for (int i = 1; i < N; i++)
    {
        if (stus[i].score == stus[i - 1].score)
            rnk[i] = rnk[i - 1];
        else
            rnk[i] = i + 1;
    }

    int ptr = 0;

    while (ptr < N && rnk[ptr] <= K)
    {
        printf("%d %s %d\n", rnk[ptr], stus[ptr].account, stus[ptr].score);
        ptr++;
    }

    return 0;
}
