#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1024

using namespace std;

double factor[MAX_N][MAX_N] = {0.0};

int N, M;
bool sex[MAX_N] = {0};

vector<vector<int> > pics;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int k;
        vector<int> ps;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            char buf[16];
            int t;
            scanf("%s", buf);

            if (buf[0] != '-')
            {
                sscanf(buf, "%d", &t);
                ps.push_back(t);
            }
            else
            {
                sscanf(buf + 1, "%d", &t);
                sex[t] = 1;
                ps.push_back(t);
            }
        }

        pics.push_back(ps);

    }

    int a, b;

    char buf[16];
    scanf("%s", buf);

    if (buf[0] != '-')
        sscanf(buf, "%d", &a);
    else
    {
        sscanf(buf + 1, "%d", &a);
        sex[a] = 1;
    }

    scanf("%s", buf);

    if (buf[0] != '-')
        sscanf(buf, "%d", &b);
    else
    {
        sscanf(buf + 1, "%d", &b);
        sex[b] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        vector<int>& ps = pics[i];
        if (find(ps.begin(), ps.end(), a) != ps.end() || find(ps.begin(), ps.end(), b) != ps.end())
        {
            int k = ps.size();
            for (int j = 0; j < k; j++)
                for (int m = j + 1; m < k; m++)
                {
                    if (sex[ps[j]] == sex[ps[m]])
                        continue;
                    if (ps[j] != a && ps[j]!= b && ps[m] != a && ps[m]!= b)
                        continue;
                    factor[ps[j]][ps[m]] += 1.0 / k;
                    factor[ps[m]][ps[j]] = factor[ps[j]][ps[m]];
                }
        }
    }

    vector<int> aa, bb;
    double ma = -1, mb = -1;

    for (int i = 0; i < N; i++)
    {
        if (i != a && sex[i] != sex[a] && factor[i][a] > ma)
        {
            aa.clear();
            aa.push_back(i);
            ma = factor[i][a];
        }
        else if (i != a && sex[i] != sex[a] && factor[i][a] == ma)
            aa.push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (i != b && sex[i] != sex[b] && factor[i][b] > mb)
        {
            bb.clear();
            bb.push_back(i);
            mb = factor[i][b];
        }
        else if (i != b && sex[i] != sex[b] && factor[i][b] == mb)
            bb.push_back(i);
    }

    if (find(aa.begin(), aa.end(), b) != aa.end() && find(bb.begin(), bb.end(), a) != bb.end())
    {
        if (sex[a])
            printf("-");
        printf("%d ", a);
        if (sex[b])
            printf("-");
        printf("%d", b);
        return 0;
    }

    for (int i = 0; i < aa.size(); i++)
    {
        if (sex[a])
            printf("-");
        printf("%d ", a);
        if (sex[aa[i]])
            printf("-");
        printf("%d\n", aa[i]);
    }

    for (int i = 0; i < bb.size(); i++)
    {
        if (sex[b])
            printf("-");
        printf("%d ", b);
        if (sex[bb[i]])
            printf("-");
        printf("%d\n", bb[i]);
    }

    return 0;
}
