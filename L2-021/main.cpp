#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct user
{
    string name;
    double avg;
    set<int> likes;
};

vector<user> us;
int N;

bool cmp(user& u1, user& u2)
{
    if (u1.likes.size() != u2.likes.size())
        return u1.likes.size() > u2.likes.size();
    return u1.avg < u2.avg;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char name[16];
        int k;
        scanf("%s %d", name, &k);
        user u;
        u.name = name;
        for (int j = 0; j < k; j++)
        {
            int t;
            scanf("%d", &t);
            u.likes.insert(t);
        }
        u.avg = (double) k / u.likes.size();
        us.push_back(u);
    }

    sort(us.begin(), us.end(), cmp);

    int t = 0;

    for (; t < 3 && t < us.size(); t++)
    {
        if (t != 0)
            printf(" ");
        printf("%s", us[t].name.c_str());
    }

    for (; t < 3; t++)
    {
        if (t != 0)
            printf(" ");
        printf("-");
    }

    return 0;
}
