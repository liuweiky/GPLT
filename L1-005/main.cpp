#include <cstdio>
#include <vector>

#define MAX_LEN 16

using namespace std;

struct student
{
    char no[MAX_LEN];
    int test, exam;
};

int N, M;
vector<student*> stus;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        student* s = new student;
        scanf("%s %d %d", s->no, &s->test, &s->exam);
        stus.push_back(s);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < N; j++)
            if (stus[j]->test == t)
            {
                printf("%s %d\n", stus[j]->no, stus[j]->exam);
                break;
            }
    }
    return 0;
}
