#include <cstdio>
#include <algorithm>
#include <map>
#include <climits>
#include <vector>
#include <queue>

#define MAX_N 8000

using namespace std;

bool graph[MAX_N][MAX_N];
int house_num[MAX_N];
int house_area[MAX_N];
bool visit[MAX_N];

map<int, int> id2hash;
map<int, int> hash2id;
int cur_hash = 0;
int N;

int local_hn = 0, local_ha = 0, local_minid = INT_MAX, local_people = 0;

struct bfsres
{
    int minid, pnum;
    double avg_hnum, avg_harea;
};

vector<bfsres> ans;

bool cmp(bfsres& r1, bfsres& r2)
{
    if (r1.avg_harea != r2.avg_harea)
        return r1.avg_harea > r2.avg_harea;
    return r1.minid < r2.minid;
}

int get_hash(int id)
{
    if (id2hash.find(id) == id2hash.end())
    {
        id2hash[id] = cur_hash;
        hash2id[cur_hash++] = id;
    }
    return id2hash[id];
}

int get_id (int h)
{
    return hash2id[h];
}

void bfs(int h)
{
    queue<int> q;
    q.push(h);
    visit[h] = true;
    while (!q.empty())
    {
        int hh = q.front();
        q.pop();
        local_hn += house_num[hh];
        local_ha += house_area[hh];
        local_people++;
        local_minid = min(get_id(hh), local_minid);

        for (int i = 0; i < cur_hash; i++)
        {
            if (!visit[i] && graph[hh][i])
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    fill_n(house_num, MAX_N, 0);
    fill_n(house_area, MAX_N, 0);
    fill_n(&graph[0][0], MAX_N * MAX_N, false);
    fill_n(visit, MAX_N, false);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int id, father, mother, k, hn, ha;
        scanf("%d %d %d %d", &id, &father, &mother, &k);
        int h = get_hash(id);
        if (father != -1)
        {
            int fh = get_hash(father);
            graph[h][fh] = graph[fh][h] = true;
        }
        if (mother != -1)
        {
            int mh = get_hash(mother);
            graph[h][mh] = graph[mh][h] = true;
        }
        for (int j = 0; j < k; j++)
        {
            int sonk;
            scanf("%d", &sonk);
            int shash = get_hash(sonk);
            graph[h][shash] = graph[shash][h] = true;
        }
        scanf("%d %d", &hn, &ha);
        house_num[h] = hn;
        house_area[h] = ha;
    }

    for (int i = 0; i < cur_hash; i++)
    {
        if (visit[i])
            continue;
        local_hn = 0;
        local_ha = 0;
        local_people = 0;
        local_minid = INT_MAX;
        bfs(i);
        bfsres r;
        r.minid = local_minid;
        r.pnum = local_people;
        r.avg_hnum = (double) local_hn / local_people;
        r.avg_harea = (double) local_ha / local_people;
        ans.push_back(r);
    }

    sort(ans.begin(), ans.end(), cmp);

    printf("%d\n", ans.size());

    for (int i = 0; i < ans.size(); i++)
    {
        printf("%04d %d %.3f %.3f\n", ans[i].minid, ans[i].pnum, ans[i].avg_hnum, ans[i].avg_harea);
    }

    return 0;
}
