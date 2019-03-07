#include <cstdio>
#include <algorithm>

#define MAX_N 10240

using namespace std;

struct user
{
    int id;
    int inout;
    user() {id = inout = 0;}
};

int N;

user users[MAX_N];
int get_pkg[MAX_N];

bool cmp(user u1, user u2)
{
    if (u1.inout != u2.inout)
        return u1.inout > u2.inout;
    if (get_pkg[u1.id] != get_pkg[u2.id])
        return get_pkg[u1.id] > get_pkg[u2.id];
    return u1.id < u2.id;
}

int main()
{
    fill_n(get_pkg, MAX_N, 0);
    for (int i = 0; i < MAX_N; i++)
        users[i].id = i;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int k;
        scanf("%d", &k);
        int n, p, uout = 0;
        for (int j = 0; j < k; j++)
        {
            scanf("%d %d", &n, &p);
            uout += p;
            users[n].inout += p;
            get_pkg[n]++;
        }
        users[i].inout -= uout;
    }

    sort(users + 1, users + 1 + N, cmp);

    for (int i = 1; i <= N; i++)
        printf("%d %.2f\n", users[i].id, users[i].inout / 100.0);

    return 0;
}
