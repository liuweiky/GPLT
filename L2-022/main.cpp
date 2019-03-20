#include <cstdio>
#include <map>
#include <vector>

using namespace std;

struct node
{
    int next, addr, data;
    node () {next = addr = -1;}
};

map<int, node> link_list;
int HEAD, N;

int main()
{
    scanf("%d %d", &HEAD, &N);

    for (int i = 0; i < N; i++)
    {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);
        node n;
        n.data = data;
        n.next = next;
        n.addr = addr;
        link_list[addr] = n;
    }

    int p = HEAD;

    vector<node> v1;
    vector<node> sorted;

    N = 0;
    while (p != -1)
    {
        N++;
        v1.push_back(link_list[p]);
        p = link_list[p].next;
    }


    for (int i = 1; i <= N / 2; i++)
    {
        sorted.push_back(v1[N - i]);
        sorted.push_back(v1[i - 1]);
    }

    if (N % 2 == 1)
        sorted.push_back(v1[N / 2]);

    for (int i = 0; i < N - 1; i++)
    {
        sorted[i].next = sorted[i + 1].addr;
    }

    sorted[N - 1].next = -1;

    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
            printf("%05d %d -1\n", sorted[i].addr, sorted[i].data);
        else
            printf("%05d %d %05d\n", sorted[i].addr, sorted[i].data, sorted[i].next);
    }


    return 0;
}
